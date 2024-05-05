#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> split(string const & str, char const ch){
    vector<string> ans;
    int n =str.size();
    int init=0;
    for (int i=0; i<n; ++i){
        if(str[i]==ch){
            ans.push_back(str.substr(init,i-init));
            init=i+1;
        }else if(i==n-1){
            ans.push_back(str.substr(init,i-init+1));
        }
    }
    return ans;
}


class sell_system{
private:
    unordered_map <string, int> prod={{"A1",0}, {"A2",1}, {"A3",2}, {"A4",3}, {"A5",4}, {"A6",5} };
    vector<string> prod_name={"A1","A2","A3","A4","A5","A6"};
    vector<int> n_price={2,3,4,5,8,6};
    vector<int> n_prod;
    vector<int> price_money={1,2,5,10};
    vector<int> n_money;
    int sum_prod;
    int one_t;
    int balance;
public:
    sell_system(){};
    ~sell_system(){};

    void update_one(){
        one_t=0;
        one_t = n_money[0] + n_money[1] *2;
    }

    void init(string str){
        balance=0;
        one_t=0;
        sum_prod=0;
        n_prod.resize(6);
        n_money.resize(4);
        vector<string> emp=split(str,' ');

        vector<string> s1=split(emp[1],'-');
        for(int i=0; i<6; ++i){
            int number = stoi(s1[i]);
            n_prod[i]=number;
            sum_prod+=number;
        }
        vector<string> s2=split(emp[2],'-');
        for(int i=0; i<4; ++i){
            n_money[i]=stoi(s2[i]);
        }
        update_one();

        cout << "S001:Initialization is successful" << endl;
    }

    void toss_coin(string str){
        // 投入硬币
        vector<string> emp=split(str,' ');
        int add_n = stoi(emp[1]);
        if(add_n!=1 && add_n!=2 && add_n!=5 && add_n!=10){
            cout << "E002:Denomination error" << endl;
        }else if(add_n >2 && add_n> one_t){
            cout << "E003:Change is not enough, pay fail" << endl;
        }else if(sum_prod==0){
            cout << "E005:All the goods sold out" << endl;
        }else {
            // 把投入的硬币添加到存钱盒中
            switch (add_n)
            {
                case 1:
                    ++n_money[0];
                    update_one();
                    break;
                case 2:
                    ++n_money[1];
                    update_one();
                    break;
                case 5:
                    ++n_money[2];
                    break;
                case 10:
                    ++n_money[3];
                    break;
                default:
                    break;
            }
            balance+=add_n;
            cout << "S002:Pay success,balance=" << balance << endl;
        }
    }

    void buy_prod(string str){
        vector<string> emp=split(str,' ');
        if(prod.count(emp[1])==0){
            cout << "E006:Goods does not exist" << endl;
        }else if(n_prod[prod[emp[1]]]==0){
            cout << "E007:The goods sold out" << endl;
        }else if(balance<n_price[prod[emp[1]]]){
            cout << "E008:Lack of balance" << endl;
        }else {
            balance-=n_price[prod[emp[1]]];
            cout << "S003:Buy success,balance=" << balance << endl;
        }
    }

    void re_coin(string str){
        string out_str="";
        if(balance==0){
            cout << "E009:Work failure" << endl;
        }else {
            for(int i=3; i>=0; --i){
                int n_c = balance/price_money[i];
                if(n_c<= n_money[i]){
                    // 余额还够找补的话
                    n_money[i]-=n_c;
                    out_str = to_string(price_money[i]) + " yuan coin number="+ to_string(n_c) + "\n" + out_str;
                    balance -=price_money[i]*n_c;
                }else {
                    // 不够找补了，那就全减
                    n_money[i]=0;
                    out_str = to_string(price_money[i]) + " yuan coin number="+ to_string(n_money[i]) + "\n" + out_str;
                    balance -= n_money[i]*n_c;
                }
            }
            balance =0;
            update_one();

            cout << out_str;
        }
    }

    void query(string str){
        vector<string> emp=split(str,' ');
        if (emp.size()!=2){
            cout << "E010:Parameter error" << endl;
            return ;
        }
        if(emp[1]=="0"){
            for(int i=0; i<6; ++i){
                cout << prod_name[i] << " " << n_price[i] << " " << n_prod[i] << endl;
            }
        }else if(emp[1]=="1"){
            for(int i=0; i<4; ++i){
                cout << price_money[i] << " yuan coin number=" << n_money[i] << endl;
            }
        }
    }

};


int main() {
    string strs;
    // {string strs="r 22-18-21-21-7-20 3-23-10-6;c;q0;p 1;b A6;c;b A5;b A1;c;q1;p 5;";
    // {string strs="r 26-3-26-2-14-10 2-1-15-18;p 5;c;c;p 2;c;b A4;c;q1;q0;p 2;b A4;p 5;q0;c;q0;q1;q0;c;c;p 10;p 1;q0;";
    {string strs="r 13-21-28-26-6-2 3-1-18-21;p 10;c;q0;p 1;b A6;q0;q1;c;c;c;q0;q1;b A3;q1;c;b A3;b A1;b A2;q1;q0;p 1;b A1;q0;q0;p 10;q1;q1;b A2;q0;q0;c;p 10;c;c;q0;p 1;b A4;p 2;c;b A5;c;p 10;b A5;q0;b A1;q0;b A2;q0;q1;";
    // while (getline(cin, strs)){
        vector<string> vec_s=split(strs,';');
        // for(auto x: vec_s){
        //     cout << x << endl;
        // }

        sell_system sell;
        for(auto s1:vec_s){
            switch (s1[0])
            {
            case 'r':
                sell.init(s1);
                break;
            case 'p':
                sell.toss_coin(s1);
                break;
            case 'b':
                sell.buy_prod(s1);
                break;
            case 'c':
                sell.re_coin(s1);
                break;
            case 'q':
                sell.query(s1);
                break;
            default:
                break;
            }
        }
    }
    
}
// 64 位输出请用 printf("%lld")
