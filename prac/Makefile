OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x


all:Text.o Cjt_textos.o main.o main.exe


Text.o: Text.cc
	g++ -c Text.cc -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
	
Cjt_textos.o: Cjt_textos.cc
	g++ -c Cjt_textos.cc -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

main.exe: main.o
	g++ -o main.exe main.o Cjt_textos.o Text.o -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
	
main.o: main.cc
	g++ -c main.cc -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
	
	
clean:
	rm *.o
	rm *.exe	