#include<bits/stdc++.h>


////////////////////////////////////////////Macro Definitions////////////////////////////
#define sync() ios_base::sync_with_stdio(false)
#define tie() cin.tie(NULL)
#define pre(n) setprecision(n)
#define fix fixed
#define print(n) cout<<n
#define printl(n) cout<<n<<"\n"
#define prints(n) cout<<n<<" "
#define nl cout<<"\n"
#define input(n) cin>>n
#define fr(i,n) for(int i=0;i<n;i++)
#define frv(i,a,n) for(i=a;i<n;i++)
#define popCount(x) __builtin_popcount(x)
#define fa(n) for(auto &i:v)

//ternary operator
#define ter(x) x ? True:False

//iterator
#define iterb(n) n.begin()
#define itere(n) n.end() 
#define fir(T) T->first()
#define sec(T) T->second()

//vector
#define vec(T) vector<T>
#define nvec(T) vector<vector<T>> 
#define fa(n) for(auto &i:v)
#define pb(v,n) v.push_back(n)

//unordered map
#define umap(T,N) unordered_map<T,N>

//pair
#define pr(T,N) pair<int,int>
#define mp(M,N) make_pair(T,N)

//set
#define st(T) set<T>

//queue
#define que(T) queue<T>
#define psh(i,n) i.push(n)
#define pp(i) i.pop() 
#define ft(i) i.front()
#define emp(i) i.empty()


using namespace std;

struct process {
    int pid;
    int AT;
    int BT;
    int ST;
    int CT;
    int TAT;
    int WT;
    int RT;
};

bool compare1(process p1, process p2) 
{ 
    return p1.AT < p2.AT;
}

bool compare2(process p1, process p2) 
{  
    return p1.pid < p2.pid;
}

int main() {

    int n;
    int tq;
    struct process p[100];
    float avg_TAT;
    float avg_WT;
    float avg_RT;
    float cpu_utilisation;
    int total_TAT = 0;
    int total_WT = 0;
    int total_RT = 0;
    int total_idle_time = 0;
    float throughput;
    int burst_remaining[100];
    int idx;

    print(pre(2) )<< fix;

    print("Enter the number of processes: ");
    input(n);
    print("Enter time quantum: ");
    input(tq);

    for(int i = 0; i < n; i++) {
        print("Enter arrival time of process ")<<i+1<<": ";
        input(p[i].AT);
        print("Enter burst time of process ")<<i+1<<": ";
        input(p[i].BT);
        burst_remaining[i] = p[i].BT;
        p[i].pid = i+1;
        nl;
    }

    sort(p,p+n,compare1);

    que(int) q;
    int current_time = 0;
    psh(q,0);
    int completed = 0;
    int mark[100];
    memset(mark,0,sizeof(mark));
    mark[0] = 1;

    while(completed != n) {
        idx = ft(q);
        pp(q);

        if(burst_remaining[idx] == p[idx].BT) {
            p[idx].ST = max(current_time,p[idx].AT);
            total_idle_time += p[idx].ST - current_time;
            current_time = p[idx].ST;
        }

        if(burst_remaining[idx]-tq > 0) {
            burst_remaining[idx] -= tq;
            current_time += tq;
        }
        else {
            current_time += burst_remaining[idx];
            burst_remaining[idx] = 0;
            completed++;

            p[idx].CT = current_time;
            p[idx].TAT = p[idx].CT - p[idx].AT;
            p[idx].WT = p[idx].TAT - p[idx].BT;
            p[idx].RT = p[idx].ST - p[idx].AT;

            total_TAT += p[idx].TAT;
            total_WT += p[idx].WT;
            total_RT += p[idx].RT;
        }

        for(int i = 1; i < n; i++) {
            if(burst_remaining[i] > 0 && p[i].AT <= current_time && mark[i] == 0) {
                psh(q,i);
                mark[i] = 1;
            }
        }
        if(burst_remaining[idx] > 0) {
            psh(q,idx);
        }

        if(emp(q)) {
            for(int i = 1; i < n; i++) {
                if(burst_remaining[i] > 0) {
                    psh(q,i);
                    mark[i] = 1;
                    break;
                }
            }
        }


    }

    avg_TAT = (float) total_TAT / n;
    avg_WT = (float) total_WT / n;
    avg_RT = (float) total_RT / n;
    cpu_utilisation = ((p[n-1].CT - total_idle_time) / (float) p[n-1].CT)*100;
    throughput = float(n) / (p[n-1].CT - p[0].AT);

    sort(p,p+n,compare2);

    cout<<endl;
    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<p[i].pid<<"\t"<<p[i].AT<<"\t"<<p[i].BT<<"\t"<<p[i].ST<<"\t"<<p[i].CT<<"\t"<<p[i].TAT<<"\t"<<p[i].WT<<"\t"<<p[i].RT<<"\t"<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_TAT<<endl;
    cout<<"Average Waiting Time = "<<avg_WT<<endl;
    cout<<"Average Response Time = "<<avg_RT<<endl;
    cout<<"CPU Utilization = "<<cpu_utilisation<<"%"<<endl;
    cout<<"Throughput = "<<throughput<<" process/unit time"<<endl;


}
