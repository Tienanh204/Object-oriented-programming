#include"FileSystem.h"

CItem::CItem() : isHidden(false), isApply(false) {}
CItem::CItem(std::string _fileName) : fileName(_fileName), isHidden(false), isApply(false) {}

std::string CItem::getName() {
	return fileName;
}
void CItem::setName(std::string _fileName) {
	fileName = _fileName;
}

//---------------
CFolder::CFolder() : CItem() {}
CFolder::CFolder(std::string _fileName) : CItem(_fileName) {}

void CFolder::add(CItem* item) {
	if (item != NULL) {
		file.push_back(item);
	}
}

void CFolder::print(bool check) {
	std::cout << "Folder: " << fileName << std::endl;
	for (auto item : file) {
		item->print(check);
	}
}

CItem* CFolder::removeByName(const std::string& name) {
	//Tim Folder -> File chon ra file/Folder can xoa
	CItem* item = nullptr;
	for (auto it = file.begin(); it != file.end(); ++it) {
		if ((*it)->getName() == name) {
			item = *it;
			file.erase(it);
			break;
		}
	}
	return item;
}

CItem* CFolder::findByName(const std::string& name) {
	for (CItem* item : file) {
		if (item->getName() == name) {//Tim Folder
			return item;
		}
		else {//Tim File
			CFolder* folder = dynamic_cast<CFolder*> (item);
			if (folder != nullptr) {
				CItem* foundItem = folder->findByName(name);
				if (foundItem != nullptr) {
					return foundItem;
				}
			}
		}
	}
	return nullptr;
}

void CFolder::setHidden(bool hidden, bool alsoApply) {
	isHidden = hidden;
	isApply = alsoApply;
	if (isApply) {
		for (CItem* item : file) {
			item->setHidden(hidden, isApply);
		}
	}
}

//---------------------------------
CFile::CFile() : CItem(), fileSize(0) {}
CFile::CFile(std::string _fileName, int _fileSize) :
	CItem(_fileName) {
	fileSize = _fileSize;
};

void CFile::print(bool check) {
	if (!isHidden || check) {
		std::cout << "File: " << fileName << " (Size: " << fileSize << ")" << std::endl;
	}
}

void CFile::setHidden(bool hidden, bool isapply) {
	isHidden = hidden;
	isApply = isapply;
}