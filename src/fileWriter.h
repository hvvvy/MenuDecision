#ifndef FILEWRITER_H_
#define FILEWRITER_H_


class CFileWriter{
private:
	const char *fileName;
public:
	CFileWriter();
	void fileWriter(std::string menu,bool empty);
};


#endif /* FILEWRITER_H_ */
