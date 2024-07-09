#include"Blog post.h"

string Post::toString() {
	stringstream ss;
	ss << "Author: " << _author << '\n'
		<< "Title: " << _title << '\n'
		<< "Content: " << _content << '\n';
	return ss.str();
}

void GraphPost::addLike() {
	_like++;
}

void GraphPost::addComment(string commenter, string content) {
	_comment.push_back({ commenter, content });
}

string GraphPost::toString() {
	stringstream ss;
	ss << Post::toString();
	ss << "\n";
	ss << "Likes: " << _like << '\n'
		<< "Comments: " << _comment.size() << '\n';

	for (auto cmt : _comment) {
		ss << "- " << cmt.first << ": " << cmt.second << '\n';
	}
	return ss.str();
}
