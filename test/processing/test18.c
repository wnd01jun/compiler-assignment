struct person {
    char name[21];
    int num;
} person;

struct person human[100000];
struct person sorted_list[100000];

int compare(const void* a, const void* b)
{
    return strcmp(((struct person*)a)->name, ((struct person*)b)->name);
}

void binary_search(int left, int right, char* str) {
    int mid, cmp;
    while (left <= right) {
        mid = (left + right) / 2;
        cmp = strcmp(sorted_list[mid].name, str);
        if (cmp == 0) {
            printf("%d\n", sorted_list[mid].num);
            return;
        }
        else if (cmp > 0) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
}

int main(void) {
    int n, m;
    char str[21];
    int i, j, index;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        scanf("%s", human[i].name);
        strcpy(sorted_list[i].name, human[i].name);
        human[i].num = sorted_list[i].num = i + 1;
    }

    qsort(sorted_list, n, sizeof(person), compare);

    for (j = 0; j < m; j++) {
        scanf("%s", str);
        if (isdigit(str[0])) {
            index = atoi(str) - 1;
            printf("%s\n", human[index].name);
        }
        else {
            binary_search(0, n - 1, str);
        }
    }

    return 0;
}