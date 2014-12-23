/*
####关联式容器共性，都是用二叉查找树来实现的，都会自动根据关键字排序
**关联式容器包括 set<K>, multiset<T>, map<K, V>, multimap<K, V>**
查找：.find(key)  ，返回第一个指向这个元素的迭代器，如果没有找到，返回.end()指向无效位置
统计：.count(key), 统计关键字key的个数
删除：.erase(key),删除关键字key相等的所有元素
区间：.lower_bound(key)取得关键字为key第一个的元素
和.upper_bound(key)取得关键字为key的最后一个元素的位置
.equal_range(key)一次取得关键字为key的元素区间，返回的是一个pair模板
插入：插入元素不用指定位置 .insert(element);//也支持指定位置
*/
