#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void ft_commit (int dfi, char *committext) {
	if (dfi == 1) {
		system("git add .");
		printf("added dotfiles");
	}
	system("git add *");
	char commit[125] = "git commit -m \"";
	char *pcm = commit;
	strcat(pcm, committext);
	strcat(pcm, "\"");
	system(commit);
}
int main(int count, char *args[]) {
	int dotfilesincluded = 0;
	if (count > 1 && args[1][0] == 'x') {
		dotfilesincluded = 1;
	}
	ft_commit(dotfilesincluded, args[1]);
}
