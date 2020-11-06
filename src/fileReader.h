#ifndef FILEREADER_H_
#define FILEREADER_H_


class CFileReader{
private:
	const char *fileName;
	std::string buf;
public:
	CFileReader();
	void fileReader(std::vector<std::string>& menulist);
	void exchangeMenulist(std::vector<std::string>& menulist);
	std::string allMenuReader(std::string& allMenu,bool& fileExists);
};


#endif /* FILEREADER_H_ */
