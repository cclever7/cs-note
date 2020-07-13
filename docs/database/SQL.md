基本操作
CREATE  创建库、表
ALTER 修改表
//添加列
ALTER TABLE mytable ADD col CHAR(20);
//删除列
ALTER TABLE mytable DROP COLUMN col;

DROP  删除表
INSERT   插入
UPDATE   更新
DELETE 	删除

查询
DISTINCT
相同值只会出现一次。它作用于所有列，也就是说所有列的值都相同才算相同。
SELECT DISTINCT col1, col2 FROM mytable;


LIMIT
限制返回的行数。可以有两个参数，第一个参数为起始行，从 0 开始；第二个参数为返回的总行数。
SELECT * FROM mytable LIMIT 0, 5;


排序
ASC：升序（默认） DESC：降序   ORDER BY
SELECT * FROM mytable ORDER BY col1 DESC, col2 ASC;


过滤
WHERE 子句可用的操作符
操作符 说明
= 等于
< 小于
> 大于
> <> != 不等于
> <= !> 小于等于
> = !< 大于等于
> BETWEEN 在两个值之间
> IS NULL 为 NULL 值
> 应该注意到，NULL 与 0、空字符串都不同。
> AND 和 OR 用于连接多个过滤条件。优先处理 AND，当一个过滤表达式涉及到多个 AND 和 OR 时，可以使用 () 来决定优先级，使得优先级关系更清晰。
> IN 操作符用于匹配一组值，其后也可以接一个 SELECT 子句，从而匹配子查询得到的一组值。
> NOT 操作符用于否定一个条件。


通配符
通配符也是用在过滤语句中，但它只能用于文本字段。
% 匹配：>=0 个任意字符；
_ 匹配： 1 个任意字符；
[ ] 匹配：可以匹配集合内的字符，例如 [ab] 将匹配字符 a 或者 b。用脱字符 ^ 可以对其进行否定，也就是不匹配集合内的字符。
Like：使用 Like 来进行通配符匹配。
SELECT * FROM mytable WHERE col LIKE '[^AB]%';


计算字段
 AS别名:计算字段通常需要使用 AS 来取别名，否则输出的时候字段名为计算表达式。
SELECT col1 * col2 AS alias FROM mytable;

CONCAT() 用于连接两个字段。许多数据库会使用空格把一个值填充为列宽，因此连接的结果会出现一些不必要的空格，使用 TRIM() 可以去除首尾空格。
SELECT CONCAT(TRIM(col1), '(', TRIM(col2), ')') AS concat_col FROM mytable;


分组
把具有相同的数据值的行放在同一组中。
可以对同一分组数据使用汇总函数进行处理，例如求分组数据的平均值等。
指定的分组字段除了能按该字段进行分组，也会自动按该字段进行排序。
SELECT col, COUNT(*) AS num FROM mytable GROUP BY col;

GROUP BY ：自动按分组字段进行排序，
ORDER BY ：也可以按汇总字段来进行排序。
SELECT col, COUNT(*) AS num FROM mytable GROUP BY col ORDER BY num;

WHERE 过滤行，HAVING 过滤分组，行过滤应当先于分组过滤。
SELECT col, COUNT(*) AS num
FROM mytable
WHERE col > 2
GROUP BY col
HAVING num >= 2;

分组规定：
1. GROUP BY 子句出现在 WHERE 子句之后，ORDER BY 子句之前；
2. 除了汇总字段外，SELECT 语句中的每一字段都必须在 GROUP BY 子句中给出；
3. NULL 的行会单独分为一组；
4. 大多数 SQL 实现不支持 GROUP BY 列具有可变长度的数据类型。

子查询
IN：子查询中只能返回一个字段的数据。
可以将子查询的结果作为 WHRER 语句的过滤条件：
SELECT *
FROM mytable1
WHERE col1 IN (SELECT col2
               FROM mytable2);


连接
内连接
内连接又称等值连接，使用 INNER JOIN 关键字。
SELECT A.value, B.value
FROM tablea AS A INNER JOIN tableb AS B
ON A.key = B.key;

外连接
外连接保留了没有关联的那些行。分为左外连接，右外连接以及全外连接，左外连接就是保留左表没有关联的行。
检索所有顾客的订单信息，包括还没有订单信息的顾客。
SELECT Customers.cust_id, Customer.cust_name, Orders.order_id
FROM Customers LEFT OUTER JOIN Orders
ON Customers.cust_id = Orders.cust_id;


组合查询
使用 UNION 来组合两个查询，如果第一个查询返回 M 行，第二个查询返回 N 行，那么组合查询的结果一般为 M+N 行。
每个查询必须包含相同的列、表达式和聚集函数。
默认会去除相同行，如果需要保留相同行，使用 UNION ALL。
只能包含一个 ORDER BY 子句，并且必须位于语句的最后。
SELECT col
FROM mytable
WHERE col = 1
UNION
SELECT col
FROM mytable
WHERE col =2;


视图
视图是虚拟的表，本身不包含数据，也就不能对其进行索引操作。
对视图的操作和对普通表的操作一样。
视图的作用
1. 简化复杂的 SQL 操作，比如复杂的连接；
2. 只使用实际表的一部分数据；
3. 通过只给用户访问视图的权限，保证数据的安全性；
4. 更改数据格式和表示。
CREATE VIEW myview AS
SELECT Concat(col1, col2) AS concat_col, col3*col4 AS compute_col
FROM mytable
WHERE col5 = val;


存储过程
存储过程可以看成是对一系列 SQL 操作的批处理。

游标
在存储过程中使用游标可以对一个结果集进行移动遍历。
游标主要用于交互式应用，其中用户需要对数据集中的任意行进行浏览和修改。

触发器
触发器会在某个表执行以下语句时而自动执行：DELETE、INSERT、UPDATE。
TRIGGER 触发器必须指定在语句执行之前还是之后自动执行，之前执行使用 BEFORE 关键字，之后执行使用 AFTER 关键字。BEFORE 用于数据验证和净化，AFTER 用于审计跟踪，将修改记录到另外一张表中。
INSERT 触发器包含一个名为 NEW 的虚拟表。
CREATE TRIGGER mytrigger AFTER INSERT ON mytable
FOR EACH ROW SELECT NEW.col into @result;

事务
基本术语：
事务（transaction）指一组 SQL 语句；
回退（rollback）指撤销指定 SQL 语句的过程；
提交（commit）指将未存储的 SQL 语句结果写入数据库表；
保留点（savepoint）指事务处理中设置的临时占位符（placeholder），你可以对它发布回退（与回退整个事务处理不同）。
START TRANSACTION
// ...
SAVEPOINT delete1
// ...
ROLLBACK TO delete1
// ...
COMMIT