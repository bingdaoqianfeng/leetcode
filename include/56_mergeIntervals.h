/**********************************************************************************
*
* Given a collection of intervals, merge all overlapping intervals.
*
* For example,
* Given [1,3],[2,6],[8,10],[15,18],
* return [1,6],[8,10],[15,18].
*
**********************************************************************************/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };

 */

class Solution {

public:
    struct Interval {
        int start;
        int end;
        Interval() : start(0), end(0) {}
        Interval(int s, int e) : start(s), end(e) {}
    };
    static bool myfunction(Interval i, Interval j){
        return i.start<=j.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.size() == 0)
            return result;

        sort(intervals.begin(), intervals.end(), myfunction);

        int index = 0;
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(result[index].end == intervals[i].start){
                result[index].end = intervals[i-1].end;
            }
            else if(result[index].end > intervals[i].start
                    && result[index].end <= intervals[i].end){
                result[index].end = intervals[i].end;
            }
            else{
                result.push_back(intervals[i]);
                index++;
            }
        }
        return result;
    }

    int testCase(){
        //Interval a(1,3), b(2,6), c(8,10), d(15,18);
        //Interval array[] = {a, b, c, d};
        Interval a(1,4), b(1,4);
        Interval array[] = {a, b};
        vector<Interval> s(array, array + sizeof(array)/sizeof(Interval));
        printV(s);

        vector<Interval> result;
        result = merge(s);
        printV(result);

        return 0;
    }
    void printV( vector<Interval>&  pt)
    {
        cout << "[ ";
        for(int j=0; j<pt.size(); j++){
            cout << "[ "<<pt[j].start<<" , "<<pt[j].end << " ] ";
        }
        cout << "] " << endl;
    }
};
