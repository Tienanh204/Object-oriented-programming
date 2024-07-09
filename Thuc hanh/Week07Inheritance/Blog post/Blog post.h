#pragma once
#include <iostream>
#include <vector>
#include<string>
#include<sstream>
using namespace std;

class Post {
private:
	std::string _author;
	std::string _title;
	std::string _content;
public:
	Post() {}
	Post(std::string author, std::string title, std::string content)
		: _author(author), _title(title), _content(content) {}
	string toString();
};

class GraphPost : public Post {
private:
	int _like;
	vector<pair<string, string>> _comment;
public:
	GraphPost() {};
	GraphPost(std::string author, std::string title, std::string content)
		:Post(author, title, content), _like(0) {}

	void addLike();
	void addComment(string commenter, string content);
	string toString();
};

