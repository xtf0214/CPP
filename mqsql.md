### 1.请根据运动会要求设计关系模式，涉及参赛学生student，参赛项目item（项目请自己编号），比赛结果competition等

student(student_id, name, gender, academy, number_area) item(item_id, name, type) // type区分男女组和混合团体

competition(comp_id, item_id, student_id, rank, score, is_record_breaking) // rank表示名次，score表示得分，is_record_breaking表示是否打破记录

#### 2.阅读后续题目，为每个关系模式设计需要的测试数据，数据量不少于5条。注意，必须有自己学号、姓名和参赛项目。 要求做完第5题，录入数据后 截图 上传

student:

| student_id | name | gender | academy      | number_area |
| ---------- | ---- | ------ | ------------ | ----------- |
| 202100001  | 张三 | 男     | 商学院       | 1001        |
| 202100002  | 李四 | 男     | 经济学院     | 3001        |
| 202100003  | 王五 | 男     | 航空宇航学院 | 6001        |
| 202100004  | 赵六 | 女     | 信息管理学院 | 4001        |
| 202100005  | 小明 | 男     | 智能工程学院 | 8001        |

item:

| item_id | name             | type |
| ------- | ---------------- | ---- |
| 1       | 男子100米        | 男   |
| 2       | 男子200米        | 男   |
| 3       | 男子400米        | 男   |
| 4       | 男子800米        | 男   |
| 5       | 男子1500米       | 男   |
| 6       | 男子110米栏      | 男   |
| 7       | 男子4×100米接力  | 男   |
| 8       | 男子4×400米接力  | 男   |
| 9       | 男子跳远         | 男   |
| 10      | 男子三级跳远     | 男   |
| 11      | 男子实心球       | 男   |
| 12      | 男子足球过杆射门 | 男   |
| 13      | 男子足球踢远     | 男   |
| 14      | 男子篮球定点投篮 | 男   |
| 15      | 男子排球发球     | 男   |
| 16      | 女子100米        | 女   |
| 17      | 女子200米        | 女   |

### 3.用关系代数查询 智能工程学院 参加400米跑的学生的学号，姓名，成绩，

π student_id, name, score (σ academy='智能工程学院' ∧ item_id='3' (student ⨝ competition ⨝ item))

### 4.用关系代数查询每个项目的参赛报名情况。

π item_id, name, count(student_id) (item ⨯ student) group by item_id, name

### 5.用sql创建关系模式中某个表，并录入以自己学号或自己参加项目开始的连续至少5条记录

创建student表：

```sql
CREATE TABLE student (
    student_id CHAR(10),
    name VARCHAR(20),
    gender CHAR(2),
    academy VARCHAR(50),
    number_area CHAR(10),
    PRIMARY KEY(student_id)
);
```

插入数据：

```sql
INSERT INTO student VALUES 
    ('202100001', '张三', '男', '商学院', '1001'),
    ('202100002', '李四', '男', '经济学院', '3001'),
    ('202100003', '王五', '男', '航空宇航学院', '6001'),
    ('202100004', '赵六', '女', '信息管理学院', '4001'),
    ('202100005', '小明', '男', '智能工程学院', '8001'),
    ('202100006', '小红', '女', '土木建筑学院', '0001'),
    ('202100007', '小李', '男', '管理工程学院', '2001'),
    ('202100008', '小张', '男', '航空发动机学院', '5001'),
    ('202100009', '小明', '女', '航空宇航学院', '6200'),
    ('202100010', '小白', '女', '智能工程学院', '8200');
```

创建item表：

```sql
CREATE TABLE item (
    item_id CHAR(10),
    name VARCHAR(50),
    type CHAR(10),
    PRIMARY KEY(item_id)
);
```

插入数据：

```sql
INSERT INTO item VALUES 
    ('1', '男子100米', '男'),
    ('2', '男子200米', '男'),
    ('3', '男子400米', '男'),
    ('4', '男子800米', '男'),
    ('5', '男子1500米', '男'),
    ('6', '男子110米栏', '男'),
    ('7', '男子4×100米接力', '男'),
    ('8', '男子4×400米接力', '男'),
    ('9', '男子跳远', '男'),
    ('
```

### 6.用sql查询 智能工程学院 参加400米跑的学生的学号，姓名，成绩，

```sql
SELECT s.student_id, s.name, c.score
FROM student s, competition c, item i
WHERE s.academy = '智能工程学院' 
    AND s.student_id = c.student_id
    AND c.item_id = i.item_id
    AND i.name = '男子400米';
```

注意，这里假设男子400米跑的项目名称为'男子400米'，需要根据实际的项目名称进行修改。

### 7.用SQL查询与自己（由学号确定）参加相同项目的同学的学号，姓名，学院和成绩

假设自己的学号为'202100005'，想要查询与自己参加相同项目的同学的学号、姓名、学院和成绩，可以使用以下SQL查询语句：

```sql
SELECT s.student_id, s.name, s.academy, c.score
FROM student s, competition c
WHERE s.student_id != '202100005'
    AND s.student_id = c.student_id
    AND c.item_id IN (
        SELECT item_id
        FROM competition
        WHERE student_id = '202100005'
    )
ORDER BY c.score DESC;
```

这里使用了子查询来查询自己参加的项目ID，然后将该ID作为条件在外层查询中使用。由于可能有多个同学参加了相同的项目，因此使用了ORDER BY来按照成绩降序排列。

### 8.用SQL查询各个学院的总分情况

假设学院信息存储在student表的academy列中，比赛成绩存储在competition表的score列中，可以使用以下SQL查询语句查询各个学院的总分情况：

```sql
SELECT s.academy, SUM(c.score) AS total_score
FROM student s, competition c
WHERE s.student_id = c.student_id
GROUP BY s.academy;
```

这里使用了GROUP BY子句来对学院进行分组，然后使用SUM函数计算每个学院的总分。注意，如果存在某个学院没有任何学生参加比赛，则该学院不会出现在结果中。如果需要包含该学院，可以使用LEFT JOIN或者RIGHT JOIN来查询。

### 9.参考“运动员号码分配区域表”中的序号，根据自己学号尾号，为不同学院建立查询视图。如学号尾号为1的同学，为商学院创建视图，能把商学院所有参赛学生的信息都显示出来。

假设运动员号码分配区域表为`athlete_number`，包含以下列：

| 序号 | 学号尾号 | 区域           |
| ---- | -------- | -------------- |
| 1    | 0        | 智能工程学院   |
| 2    | 1        | 商学院         |
| 3    | 2        | 航空宇航学院   |
| 4    | 3        | 航空发动机学院 |
| 5    | 4        | 土木建筑学院   |
| 6    | 5        | 信息管理学院   |
| 7    | 6        | 管理工程学院   |
| 8    | 7        | 经济学院       |
| 9    | 8        | 外国语学院     |
| 10   | 9        | 法学院         |

假设自己的学号是`202100005`，以学号尾号为1来为商学院创建查询视图，可以使用以下SQL语句：

```sql
CREATE VIEW v_competition AS
SELECT s.student_id, s.name, s.gender, s.academy, s.number_area, c.item_id, c.score
FROM student s, competition c
WHERE s.student_id = c.student_id
    AND RIGHT(s.number_area, 1) = 1
    AND s.academy = '商学院';
```

这里使用了RIGHT函数来获取学号的尾号，然后将其与运动员号码分配区域表进行匹配，找到对应的学院。然后，使用视图将该学院的参赛学生信息筛选出来。该视图可以使用以下SELECT语句进行查询：

```sql
SELECT * FROM v_competition;
```

查询结果将只包含商学院的参赛学生信息。如果需要为其他学院创建视图，只需要根据学号尾号和运动员号码分配区域表进行相应的修改即可。

