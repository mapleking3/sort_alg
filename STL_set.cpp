/** 
 * @filename:   STL_set.cpp
 * @brief:      STL中set的简单用法。set和map一样是一个用平衡二叉树写的模板， map可以有
 *              两个或多这个只配对，而set只有一个，当你只存放一个元素的时候，可以考虑用
 *              set,他的有点和map一样，查找很快
 * @author:     Retton
 * @version:    V1.0.0
 * @date:       2013-09-16
 * Copyright:   2012-2038 Anhui CHAOYUAN Info Technology Co.Ltd
 */
#include <iostream>
#include<set>

using namespace std;

int main()
{
    set<int> st1;
    set<int>::iterator it1;

    if (st1.empty())
    {
        cout << "empty\n";
    }

    it1 = st1.find(40);
    if (it1 != st1.end())
    {
        cout <<  *it1 << endl;
    }
    
    st1.insert(10);
    st1.insert(30);
    st1.insert(20);
    st1.insert(40);

    for (it1 = st1.begin(); it1 != st1.end(); ++it1)    
    {
        cout << *it1 << endl;
    }
    
    it1 = st1.find(40);
    if (it1 != st1.end())
    {
        cout <<  *it1 << endl;
    }

    //删除数据这里返回的是删除的个数。在这里当然是1咯
    size_t kk = st1.erase(40);
    cout << kk << endl;

    //清除全部数据。
    st1.clear();

    return 0;
}
