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
	system("git push");
}
int main(int count, char *args[]) {
	if (count > 1 && (args[1][0] == '-' && args[1][1] == 'd')) {
		ft_commit(1,args[2]);
	} else {
		ft_commit(0,args[1]);
	}
}
