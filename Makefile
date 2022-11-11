all: one exec_two exec_two2 fork2 fork3 info_inode two seek for five six seven eight eight2 eight3 nine1 nine2 ten
clean:
	rm -f Makefile~ *.o *.c~ test dup fork fork2 fork3 a.out test_files_one two seek for file1 five file sample.txt six testfile seven t1 t2 eight eight2 eight3 nine1 nine2 ten
one:
	strace echo Hello
	@echo "exit_if regroupe perror && errno (errno.h (%m))"
	@echo "---------------------------------------------------"
dup: dup.c
	gcc -o $@ $<
exec_two: dup
	./dup
	@echo "resultat du int dup(int fd) qui duplique et dup2 qui remplace"
	cat test
	@echo "==================================================="
fork: fork.c
	gcc -o $@ $<
exec_two2: fork
	./fork
	@echo "2 affichages car double processus en marche."
fork2: fork2.c
	gcc -o $@ $^
	./$@
	@echo "test trivial de fork avec le sys/wait.h et pid_t wait(int*)."
fork3: fork3.c
	gcc -o $@ $^
	./$@
	@echo "duplication de l'espace d'adressage virtuelle.(int sleep(unsigned int s);)"
info_inode: one.c
	gcc -o test_files_one $<
	./test_files_one
	@echo "test de la structure stat decrivant un inode+fonctions macros"
two: two.c
	gcc -o $@ $<
	./two
	@echo "=========================================================="
seek: three.c
	rm -f test
	gcc -o $@ $^
	./$@ test 1024
	ls -l test | cut -d ' ' -f5 #<=>| awk '{print $5}'
	cat test | od -x | head -10
for: for.c
	touch sample.txt
	gcc -o $@ $<
	./$@
	cat sample.txt
	@echo "Passage au suivant:*********************************"
five: five.c
	gcc -o $@ $<
	./$@
six: six.c
	rm sample.txt
	touch sample.txt
	gcc -o $@ $<
	./$@
seven: seven.c
	rm -f testfile
	gcc -o $@ $<
	./$@
	@echo "sys/stat.h à savoir int access(*path,int mode) et int mknod(*path,mode_t mode, dev_t dev)***************************** **********"
eight: eight.c
	rm -f t1 t2
	touch t1 
	gcc -o $@ $<
	./$@ t1 t2 #<=>link(t1,t2).
	echo "abcde" > t1
	cat t1
	@echo "HARD LINK:"
	cat t2
	@echo "miroir acces oui si on supprime t1 t2 contient tjrs les donnees"
	rm -f t1
	cat t2
	rm -f t2
eight2: eight2.c
	rm -f t1 t2
	touch t1 
	gcc -o $@ $<
	./$@ t1 t2 #<=>symlink(t1,t2).
	echo "abcde" > t1
	cat t1
	@echo "SOFT LINK:"
	cat t2
	@echo "miroir acces ~non si on supprime t1 t2 pointe vers le vide"
	rm -f t1 #cat t2(mise en commentaire donc) car ERROR!
	rm -f t2
eight3: eight3.c
	rm -f t1 t2
	touch t1
	echo hello >> t1
	gcc -o $@ $^
	./$@ t1 t2
	ls | grep t2
nine1: nine1.c
	gcc -o $@ $^
	./$@ resume_test.txt
	@echo "readfile dans nine1.c joue le role de cat en gros !!"
nine2: nine2.c
	chmod 755 resume_test.txt
	ls -l resume_test.txt | cut -d' ' -f1
	gcc $^ -o $@
	./$@ resume_test.txt
	ls -l resume_test.txt | cut -d' ' -f1
ten: ten1.c
	gcc $^ -o $@
	./$@
	@echo "FIN DES 3 PREMIERES PARTIES DU COURS EN DETAIL**************"
