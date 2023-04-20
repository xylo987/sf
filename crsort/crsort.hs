-- 插入排序

-- 插入：将列表中的某个元素按照某种规则放置到某个元素的前面
-- 排序：按照某种比较规则的先后顺序
-- 
-- 思想：
--  刚开始只有一个元素
--  获取要插入的元素，与结果集对比，如果比第一个元素大则往后继续比较，
--  如果比第一个元素小，则放在元素前面，后面的元素依次向后移动
--
-- 根据命令式语言的实践得出插入排序最多包含以下几个步骤：
--  1. 假定待排序集的第一个元素是一个已经排序好的集
--  2. 从待排序集的第二个元素开始取元素与假定已经排序好的集中的元素进行比较
--      如果小则插入那个位置，同时，已经排序好的集的元素加1
--  3. 然后从被插入的位置，原有元素依次向后移动，一直移动到取出元素的位置为止
--  4. 循环2,3直到末尾
--
--  算法演练步骤：
--  [5,4,3,2,1]
--  4              移动
--  [5, ,3, 2, 1]    -> [4, 5, 3, 2, 1]
--  3
--  [4, 5, , 2, 1]   -> [3, 4, 5, 2, 1]
--  2
--  [3, 4, 5, , 1]   -> [2, 3, 4, 5, 1]
--  1
--  [2, 3, 4, 5 , ,] -> [1, 2, 3, 4, 5]
--
--  结束
--
--  从上面可以看到，取出元素之后，由于要插入，所以首先要将元素向后移动到取出
--  元素的位置，然后才能插入，这才是正确的逻辑
--
loopx x [] = [x]
loopx x (x1:xs)
    | x1 < x = x1:(loopx x xs)
    | otherwise = x:x1:xs
loopy [] = []
loopy (x:xs) = loopx x (loopy xs)
main = print (loopy (reverse [1..1000]))

-- time 0.030