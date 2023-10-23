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

//TODO: check for if you are going with the name you want to go with
//TODO: refactor main function to use a single ? to almost eliminate that if shit

int main(int count, char *args[]) {
	if (count > 1 && args[1][0] == '-') {
		if (args[1][1] == 'd') {
			ft_commit(1,args[2]);
		} else if (args[1][1] == 'h') {
			printf("Git 69 usage:\n-d: include dotfiles\n-h: usage and tips\n");
		} else {
			printf("Check -h for usage");
		}
	} else {
		ft_commit(0,args[1]);
	}
}
