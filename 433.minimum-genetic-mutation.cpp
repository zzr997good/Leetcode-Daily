/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        //     //Common BFS
        //     queue<string> que;
        //     unordered_set<string> visiting; //This set includes the visiting element(in the queue) and the visited element(out of queue), because queue has no ability to quickly check whether some element is in the queue or not
        //     unordered_set<string> bank_set(bank.begin(),bank.end());
        //     int step=0;
        //     que.push(start);
        //     visiting.insert(start);
        //     while(!que.empty()){
        //         int sz=que.size();
        //         for(int i=0;i<sz;i++){
        //             string gene=que.front();
        //             que.pop();
        //             if(gene==end) return step;
        //             for(int j=0;j<gene.size();j++){
        //                 char origin_c=gene[j];
        //                 for(char c:"ACGT") {
        //                     gene[j]=c;
        //                     if(bank_set.count(gene)&&!visiting.count(gene)){
        //                         que.push(gene);
        //                         visiting.insert(gene);
        //                     }
        //                     gene[j]=origin_c;
        //             }
        //         }
        //     }
        //     step++;
        // }
        //     return -1;

        // Accelerate BFS
        unordered_set<string> que1;
        unordered_set<string> que2;
        unordered_set<string> visited; ////This set includes the the visited element(out of queue), because set has a strong ability to quickly check whether some element is in the queue or not
        unordered_set<string> bank_set(bank.begin(), bank.end());
        que1.insert(start);
        que2.insert(end);
        int step = 0;
        while (!que1.empty())
        {
            unordered_set<string> tmp;
            for (auto gene : que1)
            {
                if (que2.count(gene))
                    return step;
                for (int i = 0; i < gene.size(); i++)
                {
                    char original_c = gene[i];
                    for (char c : "ACGT")
                    {
                        gene[i] = c;
                        if (!que1.count(gene) && !visited.count(gene) && bank_set.count(gene))
                            tmp.insert(gene);
                        gene[i] = original_c;
                    }
                }
                visited.insert(gene);
            }
            step++;
            if (tmp.size() > que2.size())
            {
                que1 = que2;
                que2 = tmp;
            }
            else
                que1 = tmp;
        }
        return -1;
    }
};
// @lc code=end
