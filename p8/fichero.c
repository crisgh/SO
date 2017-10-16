#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>


int static buscarenDir(char* path);


int static
esTrash(char* name){
	char* lastrub;

	lastrub = strrchr(name, '.');
	if ((lastrub != NULL) && (strcmp (lastrub,".trash")==0)){
		return 1;
	}else{
		return 0;
	}
}

int static
imprimirExec(char* dname,char* path){
	if(esTrash(dname)){
		execl("/usr/bin/sha512sum","sha512sum",path,NULL);
		err(1,"exec is failed");
	}else{
		return 1;
	}
	return 0 ;
}

int static
borrarTrash(char* dname, char* path){

	if (esTrash(dname)){
		imprimirExec(dname,path);
		exit(0);
	}
	if (esTrash(dname)){

		if (unlink(path) < 0){
			errx (1, "%d: error removing %s\n", getpid(), path);

		}else{
			return 1;
		}
	}
	return 0;
}


int static
status(char* path){
	struct stat st;

	if (stat(path, &st) < 0){
			fprintf (stderr, "%d: can't look stat %s\n", getpid(), path);
			return -1;
	}
	if ((st.st_mode & S_IFMT)==S_IFDIR){
		return 1;
	}else{
		return 0;
	}
}


int static
buscarArchivo(char* path, char* dname){
	int removed = 0;

	if(status(path) == 1){
		removed = buscarenDir(path);
		//carpeta vacia -- ERROR
		if(removed <= 0){
			errx(1, "%d: no files to remove in %s/%s\n", getpid(), path, dname);
		}
	}else{
		removed = borrarTrash(dname, path);
		exit(0);
	}


	return removed;
}


int static
buscarenDir(char* path){
	DIR* dir;
	struct dirent* de;
	char* dname;
	char fpath[4*1024];
	int removed;

	removed = 0;
	dir = opendir(path);
	if(dir == NULL){
		errx(1, "%d: wrong path %s\n", getpid(), path);

	}
	while((de = readdir(dir)) != NULL){
		dname = (*de).d_name;
		if ((strcmp (dname, ".") != 0) && (strcmp (dname, "..") !=  0)){
			if (snprintf(fpath, (strlen(path)+strlen(dname)+2), "%s/%s", path, dname) < 0){
				fprintf(stderr, "%d: snprintf error:", getpid());
				exit(1);
			}
			removed = removed + buscarArchivo(fpath, dname);
			if(removed < 0){
				return 0;
			}
		}
	}
	if (closedir (dir) < 0){
		fprintf(stderr, "%d closedir:", getpid());
		exit(1);
	}
	return removed;
}


int static
resultado(int result, char* path){
	int pid;

	pid = getpid();
	if (result > 0){
		printf ( "%d: %s ok\n", pid, path);
		exit (0);
	}else{
		fprintf (stderr, "%d: no files to remove in %s\n", pid, path);
		exit (1);
	}

}


int static
WaitySumar(int pid, int argc){
	int sts, failed;

	failed = 0;
	while(wait(&sts) != pid){
		if (sts != 0){
			failed++;
		}
	}
	if (sts != 0){
			failed++;
	}
	if (failed == 0){
		printf ("all processes in this Dir were successful\n");

	}else{
		printf ("%d processes failed\n", failed);
	}
	return 0;
}


int static
paralelizarBusqueda(int argc, char* argv[]){
	int i, pid, result;
	char* path;

	for (i=0; i<argc; i++){
		path = argv[i];
		pid = fork();
		switch (pid){
		case -1://fallo
			warn("fork:");
			return -1;
		case 0: //hijo
			result = buscarenDir(path);
			resultado(result, path);

		default://padre
			WaitySumar(pid, argc);
		}
	}
	return pid;
}


int
main(int argc, char* argv[]){
	int pid;

	if (argc < 2){
		err (1, "usage: rmrubbish dir1 [dir2  dir3 ...]\n");

	}
	argc--;
	argv++;
	pid = paralelizarBusqueda(argc, argv);
	if(pid < 0){
		exit(1);
	}
	exit (0);
}
