#include"Blog post.h"
int main() {
	auto author = "Jane";
	auto tite = "3 tips to learn English effectively";
	auto content = string("To learn English effectively, you can try these 3 tips.\n")
		+ "1. Practice on a daily basis.\n"
		+ "2. Take time to understand difficult paragraphs.\n"
		+ "3. Try new things everyday";

	GraphPost gp(author, tite, content);
	gp.addLike();
	gp.addLike();
	gp.addLike();
	gp.addLike();
	gp.addLike();

	gp.addComment("Anna", "Great work.");
	gp.addComment("Blash", "This helps me a lot!");
	gp.addComment("Jack", "Thanks for your post.");

	std::cout << gp.toString();
}