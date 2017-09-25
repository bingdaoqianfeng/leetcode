
/**********************************************************************************
*
* Given an absolute path for a file (Unix-style), simplify it.
*
* For example,
* path = "/home/", => "/home"
* path = "/a/./b/../../c/", => "/c"
*
*
* Corner Cases:
*
* Did you consider the case where path = "/../"?
* In this case, you should return "/".
* Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
* In this case, you should ignore redundant slashes and return "/home/foo".
*
*
**********************************************************************************/

class Solution {
public:
/*
这道题让简化给定的路径，光根据题目中给的那一个例子还真不太好总结出规律，应该再加上两个例子 path = "/a/./b/../c/", => "/a/c"
和path = "/a/./b/c/", => "/a/b/c"， 这样我们就可以知道中间是"."的情况直接去掉，是".."时删掉它上面挨着的一个路径，
而下面的边界条件给的一些情况中可以得知，如果是空的话返回"/"，如果有多个"/"只保留一个。
那么我们可以把路径看做是由一个或多个"/"分割开的众多子字符串，把它们分别提取出来一一处理即可
*/
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;
        while (i < path.size()) {
            while (path[i] == '/' && i < path.size()) ++i;
            if (i == path.size()) break;
            int start = i;
            while (path[i] != '/' && i < path.size()) ++i;
            int end = i - 1;
            string s = path.substr(start, end - start + 1);
            if (s == "..") {
                if (!v.empty()) v.pop_back(); 
            } else if (s != ".") {
                v.push_back(s);
            }
        }
        if (v.empty()) return "/";
        string res;
        for (int i = 0; i < v.size(); ++i) {
            res += '/' + v[i];
        }
        return res;
    }

    int testCase(){
        string path("/a/./b/../../c/");
        cout << path << " ==> " << simplifyPath(path) << endl;
        return 0;
    }
};
