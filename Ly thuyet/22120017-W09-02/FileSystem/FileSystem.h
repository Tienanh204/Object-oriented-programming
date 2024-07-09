#pragma once
#include<iostream>
#include<string>
#include<vector>

class CItem {
protected:
    std::string fileName;
    bool isHidden;
    bool isApply;
public:
    CItem();
    CItem(std::string _fileName);
    virtual~CItem() {};

    std::string getName();
    void setName(std::string _fileName);

    virtual void print(bool name) = 0;
    virtual void setHidden(bool hidden, bool isApply) = 0;
};

//------------FOLDER------------
class CFolder : public CItem {
private:
    std::vector<CItem*> file;
public:
    CFolder();
    CFolder(std::string _fileName);
    ~CFolder() {};

    void add(CItem* item);
    CItem* removeByName(const std::string& name);
    CItem* findByName(const std::string& name);

    void print(bool check) override;
    void setHidden(bool hidden, bool isApply) override;
};

//------------FILE------------
class CFile : public CItem {
private:
    int fileSize;
public:
    CFile();
    CFile(std::string _fileName, int _fileSize);
    ~CFile() {}

    void print(bool check) override;
    void setHidden(bool hidden, bool isApply) override;
};