#ifndef FILE_LOCKER_H_
#define FILE_LOCKER_H_

#include <string>
#include <sys/file.h>

class file_locker {

	const std::string file;
	int fd; // What stands this for?!!!!

public:
	file_locker(const std::string &file) : file(file) {
		// linux open() system call
		fd = open(file.c_str()/*pointer to c-string with value of file*/, O_RDWR/*flag -> read-write mode*/);
		flock(fd, LOCK_EX);
	}

	~file_locker() {
		flock(fd, LOCK_UN);
	}

	std::string path() const {
		return file;
	}

};

#endif // FILE_LOCKER_H_