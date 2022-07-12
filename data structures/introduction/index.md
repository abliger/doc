# 绪论
## 什么是数据结构?
  
简而言之:数据结构是一门研究非数值计算的程序设计问题中计算机的操作对象以及它们之间的关系和操作等的学科.

重点:
* 使用计算机解决一个问题大致分为以下几步:
  1. 从具体问题中抽象出数学模型
  2. 设计一个解出问题的算法
  3. 编出程序
  4. 测试、调整直到得到结果

* 数据结构学习的内容:
  1. 离散结构,即表、树、图
  2. 数据的存储结构
  3. 文件管理

## 基本概念和术语


### 数据
  数据是所有能输入到计算机中并被计算机程序处理的符号总称.
### 数据元素
  数据元素是数据的基本单位.一个数据元素可由若干个数据项构成.
### 数据对象
  数据对象是性质相同的数据元素的集合,是数据的子集.
### 数据结构
  数据结构是相互之间存在一种或多种特定关系的数据元素的集合.
  通常有以下四种结构:

    1. 集合                 结构中的元素除了同属一个集合的关系外,无其他关系
    2. 线性结构             数据元素间存在一对一的关系
    3. 树形结构             数据元素间存在一对多的关系
    4. 图状结构或网状结构   数据元素间存在多对多的关系

  其中集合是数据元素之间关系极为松散的一种结构,可由其他结构表示它.

  <img src="https://gimg2.baidu.com/image_search/src=http%3A%2F%2Fimg-blog.csdnimg.cn%2F20191104143625859.png%3Fx-oss-process%3Dimage%2Fwatermark%2Ctype_ZmFuZ3poZW5naGVpdGk%2Cshadow_10%2Ctext_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2hpaGVsbA%3D%3D%2Csize_16%2Ccolor_FFFFFF%2Ct_70&refer=http%3A%2F%2Fimg-blog.csdnimg.cn&app=2002&size=f9999,10000&q=a80&n=0&g=0n&fmt=auto?sec=1660229180&t=2e9b454d0260803c44f0391890c5b667" alt="四种基本结构关系" />

  数据结构在计算机中的表示(又称映像)称为数据的物理结构,也叫做存储结构.其中存储结构在计算机存在两种不同的表示方法:
    
    1. 顺序映像(顺序存储结构)      借助元素在存储器中的相对位置表示数据间的逻辑关系
    2. 非顺序映像(链式存储结构)    借助指示元素的指针表示数据元素间的逻辑关系
### 数据类型
  数据类型是一个值的集合和定义在这个值集上的一组操作的总称.
  数据类型大体分为两类:

    1. 原子类型(基本数据类型)
    2. 结构类型(引用数据类型)

### 抽象数据类型
  抽象数据类型是指一个数学模型以及定义在该模型上的一组操作.

### 多形数据类型
  多形数据类型是指其值的成分不确定的数据类型.类似多态?