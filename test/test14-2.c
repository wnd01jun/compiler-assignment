int main(){
	int N, i;
	int max = 0;
	float sum = 0;
	int *scores;

	scanf("%d", &N);

    scores = (int*)malloc(sizeof(int) * N);
	
	for(i = 0; i < N; i++){
		scanf("%d ", &scores[i]);
		if(scores[i] > max)
			max = scores[i];
	}
	for(i = 0; i < N; i++){
		if(scores[i] < max)
			scores[i] = (float)scores[i]/max*100;
		sum = sum + scores[i];
	}
	
	printf("%f", sum/N);
}