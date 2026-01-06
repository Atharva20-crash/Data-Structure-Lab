#include<stdio.h>
void main() {
	int n, key, flag = 0, pos = -1;
    int arr[100], i;

    // Read array size
    scanf("%d", &n);

    // Read array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read key element
    scanf("%d", &key);

    // Linear search logic
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            flag = 1;
            pos = i;
            break;
        }
	
	
	
	
	
	
	
	
	
	}
	if (flag == 1) {
		printf("found at position %d\n", pos);
	} else {
		printf("%d not found\n", key);
	}
}
