int main(){
	int N;
	int max = 0;
	float sum = 0;
	scanf("%d", &N);
	int scores[N];
	
	for(int i = 0; i < N; i++){
		scanf("%d ", &scores[i]);
		if(scores[i] > max)
			max = scores[i];
	}
	for(int i = 0; i < N; i++){
		if(scores[i] < max)
			scores[i] = (float)scores[i]/max*100;
		sum = sum + scores[i];
	}
	
	printf("%f", sum/N);
}