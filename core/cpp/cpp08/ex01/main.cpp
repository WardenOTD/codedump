#include "Span.hpp"

std::vector<int> ctos(char *argv){

	for (int i = 0; argv[i]; i++){
		if (!isdigit(argv[i]) && argv[i] != ' ')
			throw Invalid();
	}

	char	*ptr;
	std::vector<int> ret;
	ptr = strtok(argv, " ");
	while (ptr){
		ret.push_back(atoi(ptr));
		ptr = strtok(NULL, " ");
	}
	return (ret);
}

int main(int argc, char **argv){
	if (argc > 1){
		std::vector<int> user = ctos(argv[1]);
		Span span(user.size() + 1);
		span.addMoreNumber(user);
		cout << "longest span : " << span.longestSpan() << endl;
		cout << "shortest span : " << span.shortestSpan() << endl;
	}
}
