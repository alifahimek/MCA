#include <stdio.h>

int main(){
    int n;
    printf("enter the size of universal set");
    scanf("%d", &n);
 if (n > n || n < 0) {
		printf("Invalid size!\n");
		return;
	}

printf("enter the elnts of universal set \n");
int u[n];
for (int i=0;i<n;i++){
      printf(" element %d :",i + 1);
    scanf("%d",&u[i]);
  
}



int size1;

printf("enter the size of  set1");
    scanf("%d", &size1);
if (size1 > n || size1 < 0) {
		printf("Invalid size!\n");
		return;
	}

printf("enter the elnts of  set1 \n");
int s1[size1];
for (int i=0;i<size1;i++){
      printf(" element %d :",i + 1);
    scanf("%d",&s1[i]);
  
}

int size2;

printf("enter the size of  set2");
    scanf("%d", &size2);
if (size2 > n || size2 < 0) {
		printf("Invalid size!\n");
		return;
	}

printf("enter the elnts of  set2 \n");
int elt;
int s2[size2];
for (int i=0;i<size2;i++){
      printf(" element %d :",i + 1);
    scanf("%d",&elt);
 
  
}

	int S1[n], S2[n];
	for (int i = 0; i < n; i++) {
		S1[i] = 0, S2[i] = 0;
		for (int j = 0; j < size1; j++) {
			if (u[i] == s1[j]) {
				S1[i] = 1;
				break;
			}
		}
		for (int j = 0; j < size2; j++) {
			if (u[i] == s2[j]) {
				S2[i] = 1;
				break;
			}
		}
	}

    int setUnion[n];
	for (int i = 0; i < n; i++) {
		if (S1[i] == 1 || S2[i] == 1)
			setUnion[i] = 1;
		else
			setUnion[i] = 0;
	}



    	int setIntersection[n];
	for (int i = 0; i < n; i++) {
		if (S1[i] == 1 && S2[i] == 1)
			setIntersection[i] = 1;
		else
			setIntersection[i] = 0;
	}


for (int i = 0; i < n; i++)
{
    printf("%d\n",setUnion[i]);
}
for (int i = 0; i < n; i++)
{
    printf("%d\n",setIntersection[i]);
}

// for (int i = 0; i < size1; i++)
// {
//     printf("%d\n",s1[i]);
// }


// for (int i = 0; i < size2; i++)
// {
//     printf("%d\n",s2[i]);
// }

}