



                                          /*------------بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ-----------*/


                           /*رَبِّ أَعِنِّي وَلَا تُعِنْ عَلَيَّ، وَانْصُرْنِي وَلَا تَنْصُرْ عَلَيَّ، وَامْكُرْ لِي وَلَا تَمْكُرْ عَلَيَّ،
                           
                                  وَاهْدِنِي وَيَسِّرِ الهُدَى إِلَيَّ، وَانْصُرْنِي عَلَى مَنْ بَغَى عَلَيَّ*/


/*----------------ایک دن آئے گا، مجھے پیار کیا جائے گا، میری تعریف کی جائے گی اور وہ میری عزت کریں گے۔----------------*/


#include <bits/stdc++.h>
using namespace std;
#define ok cout << "YES" << "\n";
#define nt cout << "NO" << "\n";
#define nl cout << "\n";
#define pl first
#define dr second
#define und emplace_back
#define bhr pop_back
#define pb make_pair
#define out(A) cout << A << '\n';
#define MOD 998244353
#define mod 1000000007
#define inf 9223372036854775807
#define all(z) (z).begin(), (z).end()
#define loop(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef vector<int> si;
typedef vector<ll> sl;
typedef vector<pair<ll, ll>> spl;
typedef vector<vector<ll>> ssl;
typedef unsigned long long ull;
typedef long double lld;


/* -----------Some important pre-calculated function-------------*/

/*-------------Has Function for avoiding to hacked---------*/

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
      
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<long long, int, custom_hash> safe_map;

/*-------------Returns minimum of two numbers---------*/


int min(int x, int y) 
{
    return y ^ ((x ^ y) & -(x < y));
}

/*-------------Returns maximum of two numbers---------*/

int max(int x, int y) 
{
    return x ^ ((x ^ y) & -(x < y));
}

/*-------------------Recursive addition of integers------------------*/

int add(int a, int b) 
{
    if (b == 0)
        return a;
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return add(sum, carry);
}

 /*------------------Iterative addition of two integers-----------------*/


int Add(int a, int b)
{
    while (b != 0)
    {
        int sum = a ^ b;
        int carry = (a & b) << 1;
        a = sum;
        b = carry;
    }
    return a;
}


/*------------Recursive subtraction of two integers-------------*/

int subtract(int a, int b) 
{
    if (b == 0)
        return a;
    return subtract((a ^ b), ((~a) & b) << 1);
}

/*--------------Iterative subtraction of two integers---------------*/


int Subtract(int x, int y) 
{
    while (y != 0)
    {
        int borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    return x;
}


/*--------------Russian Peasant using bitwise operator--------------*/


ll mul(int a, int b) 
{
    ll ans = 0;
    while (b)
    {
        if (b & 1)
        {
            ans +=(ll)a;
        }
        a = a << 1;
        b = b >> 1;
    }
    return ans;
}

/*----------------------Division-------------------*/


int divide(int a, int b)
{
    int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;
    a = abs(a);
    b = abs(b);
    int q = 0, tmp = 0;
    for (int i = 31; i >= 0; --i)
    {
        if (tmp + (b << i) <= a)
        {
            tmp += (b << i);
            q |= (1LL << i);
        }
    }
    return sign * q;
}


/*--------------check if a number is a power of 2---------------*/

bool ispowerof2(int n) 
{
    return (__builtin_popcountll(n) == 1);
}

 /*--------------Computes gcd using Euclid's algorithm------------*/

int gcd(int a, int b) 
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


 /* ----------------Recursive power function-----------------------*/

int binpow(int a, int b)
{
    if (b == 0)
        return a;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

/*---------------Iterative power function-----------------------------*/

int powint(int a, int b) 
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll powll(ll a, ll b) 
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


ll ceil_div(ll n, ll d) { return n % d == 0 ? n / d : n / d + 1; }

/*--------<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>----------*/

ll gcdll(ll n, ll d) { if (n == 0LL) { return d; } return gcd(d % n, n); }

/*--------<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>----------*/

ll sum(vector<ll> & nums){
    ll ans=0;
    loop(i,0,nums.size()){
        ans+=nums[i];
    }
    return ans;
}

/*--------<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>----------*/

sl s1dv(int n) {
    sl a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    return a;
}

/*------------------Modular Exponentiation Iterative-----------------*/

ll modpowll(ll a, ll b, ll m) {
    if (b == 0) return 1; 
    ll ans = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2)
            ans = (ans * a) % m;
        b = b >> 1;
        a = (a * a) % m;
    }
    return ans % m;
}

/*--------<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>----------*/

ll ncr(ll n, ll r, ll p) {
    if (r == 0)
        return 1;
    ll fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % p;
    return (((fac[n] * modpowll(fac[r], p - 2, p)) % p) * ((modpowll(fac[n - r], p - 2, p)) % p)) % p;
}


/*--------------------------Mex calculation-----------------------*/

int mex(vector<int> const& A) {
    static bool used[200005+1] = { 0 };
    for (int x : A) {
        if (x <= 200005)
            used[x] = true;
    }
    int result = 0;
    while (used[result])
        ++result;


    for (int x : A) {
        if (x <= 200005)
            used[x] = false;
    }

    return result;
}

/*--------Check if a number odd or even----------*/

bool oe(int x) {
    if (x == 0) {
        return true;
    }
    if ((x & 1) == 0) {  
        return true;
    }
    return false;
}

/*--------<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>-----------*/

bool isPerfectSquare(long long n)
{
    if (n <= 1) {
        return true;
    }
    long long left = 1, right = n;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;
        if (square == n) {
            return true;
        }
        else if (square < n) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}


/*--------<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>-----------*/


vector<int> primeFactorization(int n) {

    vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        factors.push_back(n);
    }
   return factors;
}

/*--------<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>-----------*/
bool isVowel( char& ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' ){
        return true;
    }
    return false;
}
 
/*--------<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>-----------*/

    int subArraySum(vector<int>& arr, int tar) {
    map<long long, int> mp; 
    long long sum = 0;       
    int ans = 0;
    
    mp[0] = 1;  
    
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];  
        
        if(mp.find(sum - tar) != mp.end()) {
            ans += mp[sum - tar];  
        }
        
        mp[sum]++;
    }
    
    return ans;
}

/*-------------Kadane's Method for Maximum subarray Sum----------*/

int maxSubarraySum(vector<int> &arr) {
        
        int maxiSum = INT_MIN;
        int n = arr.size();
        int currSum = 0;
        for(int i=0;i<n;i++){
            currSum = max(currSum+arr[i],arr[i]);
            maxiSum = max(maxiSum,currSum);
        }
        return maxiSum;
    }


/*----------------Check if a number is prime or not.------------------*/

bool isprime(int x) 
{
    if (x < 2)
        return false;
    if (x < 4)
        return true;
    if (!(x & 1))
        return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}


const int MXX = 1e5 + 69;
int fact[MXX], invfact[MXX];

/*--------------------Inverse Mod Function--------------------------*/

ll modinv(int k) 
{
    return modpowll(k, MOD - 2, MOD);
}
void combinatorics()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < MXX; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
 
    invfact[MXX - 1] = modinv(fact[MXX - 1]);
    for (int i = MXX - 2; i >= 0; i--)
    {
        invfact[i] = invfact[i + 1] * (i + 1);
        invfact[i] %= MOD;
    }
}


/*------------------------nCr calculation------------------------*/

int nCr(int x, int y) 
{
    if (y > x)
        return 0;
    int num = fact[x];
    num *= invfact[y];
    num %= MOD;
    num *= invfact[x - y];
    num %= MOD;
    return num;
}


/*-------------------Transforms a string into lower case-------------------*/


string lwr(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}


/*-------------------Converts a string into uppercase--------------------*/


string upr(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}


/*-------------------function to factorize a given number----------------------*/

vector<int> factorize(int n)
{
    vector<int> v;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (i * i != n)
            {
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
    return v;
}

/* ---------this function calculates (a*b)%c taking into account that a*b might overflow ------------------*/

ll mulmod(ll a,ll b,ll c){
    ll x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

/*------------------Start of the main function------------*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Number_Of_Works;
    cin>>Number_Of_Works;
    while(Number_Of_Works--){
      
    }

    return 0;

}


/*---MEMORIZATION-----------MEMORIZATION-----------MEMORIZATION-----------MEMORIZATION-------------*/

/*
    ! stuff you should look for
        * int overflow, array bounds
        * special cases (n=1)?
        * boundary cases
        * do something instead of nothing and stay organized.
        # BELIEVE in yourself.
*/
/*
? Some basic stuff that you should learn:
 
        ? Sets : Unique element container.
            ! set<int,greater<int> > s; // to order the set in descending order
            * To check if an element is in a set : s.count(x)
            ! Another method to check if an element exists in a set :if(s.find(x)!=s.end()){ // condition  }
            * Value of First Element of Set : *(s.begin())
            * Value of Last Element of Set : *(--s.end())
            ! To erase an element by value: s.erase(x);
            * begin() - returns an iterator to first element of set. The value of the element can be accessed using *(s.begin())
            * end() - Returns an iterator to the theoretical element that follows last element in the set.
            * size() - Returns the number of elements in the set.
            * max_size() - Returns the maximum number of elements that the set can hold.
            * empty() - Returns whether the set is empty.
            ! find(x) - Returns an iterator to the element ‘x’ in the set if found, else returns the iterator to end.
            * erase(x)– Removes the value ‘x’ from the set. It erases an element by value
            * count(x) - Returns 1 or 0 based on the element ‘x’ is present in the set or not. It's the best way to check for the presence of an element.
            * lower_bound(x) – Returns an iterator to the first element that is equivalent to ‘x’ or definitely will not go before the element ‘x’ in the set.
              lower_bound can also be thought as the smallest element greater than or equal to x
            * Return reverse iterator to reverse beginning: (s.rbegin())
            * Set to be sorted in decreasing order: set<int, greater<int> >
            * emplace() : If the function successfully inserts the element (because no
                    equivalent element existed already in the set), the function returns a
                    pair of an iterator to the newly inserted element and a value of true.
            * const bool is_in = s.find(x) != s.end(); check if an element is in the set.
            ! myset.erase(x) #directly by value. logarithmic complexity
            ! myset.erase(iteratortoanelement,s.end())
            * for_each(all(s),do_something);
            ! set<int> :: iterator it = myset.find(60);
 
        ? Vectors
            @ Erase elemnents by value rather than position
            # vec.erase(std::remove(vec.begin(), vec.end(), 8), vec.end());
            *
            @ Erase duplicates in a sorted array
            # v.erase(unique(v.begin(), v.end()), v.end());
            *
            @ Erase elements by position
            # vec.erase(vec.begin() + 1);
            vector<int> v; v.resize(n,0); // resizes the vector and initializes it too.
            front(), back(), push_back(), pop_back()
            * begin() - Returns an iterator pointing to the first element in the vector
            * end() - Returns an iterator pointing to the theoretical element that follows the last element in the vector
            * rbegin() - Returns a reverse iterator pointing to the last element in the vector (reverse beginning).
            * rend() - Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
            * cbegin(),cend(),crbegin(),crend()
            * size() - Returns the number of elements in the vector.
            * max_size() -  Returns the maximum number of elements that the vector can hold.
            * capacity() - Returns the size of the storage space currently allocated to the vector expressed as number of elements.
            * resize() - Resizes the container so that it contains ‘n’ elements.
            * empty() - Returns whether the container is empty.
            * shrink_to_fit() - Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
            * reserve() - Requests that the vector capacity be at least enough to contain n elements.
            * [i] - Returns a reference to the element at position ‘i’ in the vector
            * at(i) - Returns a reference to the element at position ‘i’ in the vector
            # front() - Returns a reference to the first element in the vector
            # back() - Returns a reference to the last element in the vector
            * data() - Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
            * assign() - It assigns new value to the vector elements by replacing old ones
            * push_back() - It push the elements into a vector from the back
            # pop_back() - It is used to pop or remove elements from a vector from the back.
            ! insert() - It inserts new elements before the element at the specified position
            * erase() - It is used to remove elements from a container from the specified position or range
            * swap() - It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
            * clear() - It is used to remove all the elements of the vector container
            * emplace() - It extends the container by inserting new element at position
            * emplace_back() - It is used to insert a new element into the vector container, the new element is added to the end of the vector
            # for (auto it = myvector.begin(); it != myvector.end(); ++it)  // normal iterator
            # for (auto t:v)
 
        ? Queue
            * empty() - Returns whether the queue is empty.
            * size() - Returns the size of the queue.
            * emplace() - Insert a new element into the queue container, the new element is added to the end of the queue.
            * front() - front() function returns a reference to the first element of the queue.
            * back() - returns a reference to the last element of the queue.
            * push(x) - adds the element ‘x’ at the end of the queue
            * pop() - deletes the first element of the queue
 
        ? Priority_Queue
            ! priority_queue <int, vector<int>, greater<int>> pq; // to make a priority queue in descending order
            * empty() - returns whether the queue is empty.
            * size() -  returns the size of the queue.
            # top() -  Returns a reference to the top most element of the queue
            * push(x) - adds the element ‘x’ at the end of the queue.
            * pop() -  deletes the first element of the queue.
            * swap() -  swap the contents of one priority queue with another priority queue of same type and size.
            * emplace() - insert a new element into the priority queue container, the new element is added to the top of the priority queue.
 
        ? Deque
            Double ended queues are sequence containers with the feature of expansion and contraction on both the ends.
            They are similar to vectors, but are more efficient in case of insertion and deletion of elements.
            Unlike vectors, contiguous storage allocation may not be guaranteed.
            * insert()
            * rbegin()
            * rend()
            * assign()
            * resize()
            * push_front()
            * push_back()
            * pop_front()
            * pop_back()
            * front()
            * back()
*/
