class Solution {
public:
bool check ( long long key, vector <int> & ranks , int cars ){
    long long res = 0;
    for ( int i = 0 ; i < ranks.size() ;  i++ ){
        res += ( long long ) ( sqrt ( key / ranks[i] ) );
        if ( res >= cars ) return true;
    }
    return false;
}
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1;
        unsigned long long r = 1LL * ( (long long) *min_element(ranks.begin() , ranks.end()) * (long long) cars * (long long ) cars );
        while ( r > l  ){
            long long mid = ( l + r ) / 2;
            if ( check ( mid , ranks , cars ) ) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};