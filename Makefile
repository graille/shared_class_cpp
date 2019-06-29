edit : 
	g++ main_with_process.cpp -o with_process.out
	g++ main_with_thread.cpp -pthread -o with_thread.out
clean :
	rm with_process.out
	rm with_thread.out