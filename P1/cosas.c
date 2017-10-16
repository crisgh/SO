---------Saber el pid----------

pid_process(int argc, char* argv[])
{
	pid_t p;

	p = getpid();
	printf("pid is %d\n", p);n
	exit(0);
}
-------------SABER EL USER-------- echo $USER
int
main(int argc, char* argv[])
{
	int uid;
	struct passwd *p;

	uid = getuid();
	p = getpwuid(uid);
	if (p == NULL) {
		err(1, "no passwd for uid");
	}
	printf("user name is %s\n", p->pw_name);
	exit(0);
}
