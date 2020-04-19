
#include <algorithm>
#include <iostream>

#include <boost/random.hpp>
#include <boost/random/random_device.hpp>
#include <boost/timer/timer.hpp>

int score_array[21][3];

int main(){

	//boost::random::random_device seed_gen;
	boost::random::mt19937 gen;
	boost::random::uniform_int_distribution<> dist(0,100);

	using namespace std;

	boost::timer::cpu_timer timer;

	cout << "" << endl ;
	for(int i=0; i<21; i++){
		score_array[i][0] = 100 ;
		score_array[i][1] = 100 ;
		while(score_array[i][0] + score_array[i][1] > 100){
			score_array[i][0] = dist(gen);
			score_array[i][1] = dist(gen);
		}
		score_array[i][2] = 100 - (score_array[i][0] + score_array[i][1]) ;
		if(i < 9){
			cout << " SCORE LIST 0" << i+1 << " : [" << score_array[i][0] << ", " << score_array[i][1] << ", " << score_array[i][2] << "]" << endl ;
		}else{
			cout << " SCORE LIST "  << i+1 << " : [" << score_array[i][0] << ", " << score_array[i][1] << ", " << score_array[i][2] << "]" << endl ;
		}
	}
	cout << "" << endl ;
	
	int temp_sum ;
	string S = "000000011111112222222" ;
	int max_sum = 0 ;
	string max_index ;
	int C = 0 ;

	do{
		temp_sum = 0 ;
		for(int i=0; i<21; i++){
			temp_sum += score_array[i][int(S[i])-48];
		}
		if(temp_sum > max_sum){
			max_sum = temp_sum ;
			max_index = S ;
		}
		C++;
		if(C == 100000000){
			cout << S << endl ;
			C = 0 ;
		}
	}while(next_permutation(S.begin(), S.end()));

	cout << " MAX SCORE = " << max_sum << " : INDEX = " << max_index << endl ;
	cout << "" << endl ;

	std::string result = timer.format();
	cout << result << endl ;
	return 0 ;
}
