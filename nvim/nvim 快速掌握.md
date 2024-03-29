# nvim 快速掌握

## 光标移动
1. 移动光标

```
    上          k
  左  右  =>  h   l 
    下          j
```

2. 词移动

```
           ge      b          w                             e
           <-     <-         --->                          --->
    This is-a line, with special/separated/words (and some more). 
       <----- <-----     .   -------------------->         ----->
         gE      B                   W                       E
           ge      b          w                             e
```

3. 移动到行首或行尾

```
                ^
         <------------
    .....This is a line with example text 
    <----------------- . --------------->
            0                   $
```

4. 移动到指定字符

```
                             Ta          ta
                            <---    ------------>
    To err is human.  To really foul up you need a computer.
                           <---- .  ------------->
                            Fa           fa
```

'f' 和 't' 命令可以使用 ';' 命令重复, ',' 命令反向重复.

5. 括号匹配

```
                %
             <----->
    if (a == (b * c) / d) 
       <---------------->
                %
```

6. 移动到指定行

```
                +---------------------------+ 
        H -->   | text sample text          | ^    |  <-- 首行
                | sample text               | |    |
                | text sample text          | | gg |  5G
                | sample text               | |    |
        M -->   | text sample text          | |    v
                | sample text               |
                | text sample text          | |
                | sample text               | | G
        L -->   | text sample text          | v
                +---------------------------+
```

除了这些命令,% 也可以进行模糊的移动.如 40% 光标移动文件内容的 40% 处 

7. 滚屏

| 上滚   |                  | 下滚   |                  |
| ------ | ---------------- | ------ | ---------------- |
| CTRL-D | 文字向上滚动半屏 | CTRL-U | 文字向下滚动半屏 |
| CTRL-E | 文字向上滚动一行 | CTRL-Y | 文字向下滚动一行 |
| CTRL-F | 文字向上滚动整屏 | CTRL-B | 文字向下滚动整屏 |

| 光标重定位 |                          |
| ---------- | ------------------------ |
| zt         | 光标所在行移动到屏幕首行 |
| zz         | 光标所在行移动到屏幕中间 |
| zb         | 光标所在行移动到屏幕底部 |

8. 标记

使用 ''' 或者 '`' 可以执行跳转操作. 以下符号是软件自动标记的位置

        '       跳转前的光标位置
        "       最后编辑的光标位置
        [       最后修改的开始位置
        ]       最后修改的结束位置

可以用如下命令取得所有的标记的列表: 

        :marks

使用 'm' 命令可以设置局部标记.如使用 

        ms 

标记当前的光标位置.再使用

        's 

移动到标记位置

标记的大小写会影响标记的生效范围
小写的标记只在创建标记的文件中生效
大写标记在全局生效
## 编辑

1. 插入

```
i   在光标前插入字符
o   在光标下面插入一行并移动到行首
a   在光标后插入字符
I   在光标行首插入字符
O   在光标上面插入一行并移动到行首
A   在光标行尾插入字符
```

2. 删除

使用 x 命令可以删除光标所在字符
使用 d 命令后接范围,删除所输入范围到字符.如

        d2w

删除光标所在后边两个单词

        daw

删除光标所在的单词

        d$

删除光标位置到行尾

删除一整行

        dd

3. 替换

使用 c 命令修改所选内容,使用形式如 d 命令

修改一整行
        
        cc

其他常用命令

        X  表示  dh  (删除光标左边的字符)
        D  表示  d$  (删除到行尾)
        C  表示  c$  (修改到行尾)
        s  表示  cl  (修改一个字符)
        S  表示  cc  (修改一整行)

替换单个字符

使用 r 命令,如

        rt

使当前光标到字符替换为 t ,且不会进入编辑模式

使用 R 进入替换模式

5. 高级替换

":substitute" 命令(缩写 ":s")使你可以在连续的行中执行字符串替换。下面是这个命令的一般形式:

        :[range]substitute/from/to/[flags]

[range] 不指定,表示 :s 命令只作用在当前行

    1. 命令范围
    使用 , 分割范围,如
            :1,5s/this/that/g                       1 到 5 行 使用 that 替换 this
            :?^Chapter?,/^Chapter/s=grey=gray=g     在 Chapter 间 使用 gray 替换 grey
            :.+3,$-5s/this/that/g                   当前行下面单行到文件结束进行替换
            :'t,'bs/this/that/g                     使用标记范围进行替换
            :%s/\([^,]*\), \(.*\)/\2 \1/            把形如 "Last, First" 改成 "First Last"
            :%s/\s\+$//                             删除多余的空格
    2. 参数 flags
            g                                       全局替换 在选定范围中到每一处进行替换
            c                                       替换前提示
            e                                       如果找不到替换的单词不报错
    3. 分隔符
    一般使用 '/' 分隔符,如果替换的内容有 '/' 可以使用 '+' 或 '=' 等分割

":global" 命令(缩写g)使你找到一个匹配点并且在那 里执行一个命令。它的一般形式是:

        :[range]global/{pattern}/{command}

如

        :g+//+s/foobar/barfoo/g

到意思是找到 // 符号的行,使用 barfoo 替换所有的 foobar

6. 重复修改

使用 . 命令,它会重复出了 u(撤销) 和 CTRL—R(重做) 命令外的修改命令

7. 黏贴复制

```
y 软件内拷贝
p 黏贴 y 命名的拷贝内容
"*y 拷贝到剪切板
"*p 从剪切板黏贴

yy 拷贝一整行
```

* 号是一个特殊的寄存器,实际上 " 符号后可以用 a 到 z 任意字符代表到寄存器,它在文件间到复制相当有用

8. 撤销重做

        u       撤销
        CTRL-R  重做

9. 删除光标下的空行

使用 J 命令移除光标下的空行

J 命令实际上是删除所在行处的回车符

10. 快速替换大小写

        g~[range]       交换大小写     (a -> A 而 A -> a)
        gU[range]       转换成大写     (a -> A 而 A -> A)
        gu[range]       转换成小写     (a -> a 而 A -> a)

11. 平移

        <<      向左平移
        >>      向右平移

12. 读写一部分文件

        :read file      文件内容插入到当前位置
        :0read file     文件内容插入到第 0 行
        :.,\write file  写入当前位置到文件末的全部行到文件中
        :.write file    把当前行写入文件中
        :.write >> file 把当前行追加到文件中

13. 自动换行

        :set textwidth=number   设置多长自动换行
        gq[文本对象]            文本对象自动换行
        gggqG                   全文自动换行 gg 移动到首行,gq 自动换行,G 自动换行到行尾

14. 可视模式下的重复 

        gv              再次选择上次可是模式选择的文本

15. 数字加减

        CTRL-A          光标数字加 1
        3 CTRL-A        光标数字加 3
        CTRL-X          光标数字减 1
### 文本对象

使用编辑命令会要求删除一句话或者一段文字,使用文本对象会方便操作

        aw              一个单词
        as              一个句子
        ap              一个段落
        iw
        is
        ip              一个单词句子段落,不包括周围等空格
        a(|[|<|{|'等
        a)|]|>|}|'      一个符号范围包括符号
        i(|[|<|{|'等
        i)|]|>|}|'      一个符号范围不包括符号
        at              一个标签块
        it              一个标签块,不包含标签,用于html


### 编辑多个文件

1. 一次打开多个文件 

        vim one.c two.c
        vim one.*
        vim *.md

2. 编辑文件

        :next               命令编辑下一个文件
        :wnext              命令保存并编辑下一个文件
        :args               查看文件列表
        :previous           回到前一个文件
        :wprevious          保存再移动到前一个文件
        :last               移动到最后到文件
        :first              移动到第一个文件
        :2next              向后跳转两个文件
        :args *.txt         不退出nvim,编辑其他 txt 文本
        :saveas filename    另存为 filename
        :file filename      改变文件名,但不保存
        :edit filename      打开文件
        :view filename      只读模式打开文件

3. 文件间快速跳转

要在两个文件间快速跳转，按 CTRL-^.

4. 重返某个文件

        :oldfiles       查看编辑过的文件列表

出现文件列表后,再使用 :e #<number 命令来进入文件.也可以使用

        :browse oldfiles

更方便的进入

5. 进入光标下所指文件

        gf

### 会话

会话可以保存诸如文件列表、窗口布局、全局变量、选项、以及其它信息.
下面这个命令创建一个会话文件: 

        :mksession vimbook.vim

如果你以后要还原这个会话，你可以用这个命令: 

        :source vimbook.vim

如果你要启动 Vim 并还原某个特别的会话，你可以用下面这个命令: 

        vim -S vimbook.vim

常用在多个项目间的切换
## 窗口

1. 创建窗口

        :split                  水平分割窗口
        :vsplit                 垂直分割窗口
        :close                  关闭窗口
        :only                   关闭其他窗口
        :split|vsplit file      使用另一窗口打开文件
        :new                    编辑新文件
        :3split file            以3行窗口编辑文件

2. 编辑窗口

        CTRL-w w                窗口跳转
        CTRL-w +                扩大窗口
        5 CTRL-w +              扩大 5 行窗口
        CTRL-w -                缩小窗口
        
        CTRL-W h                跳转到左边的窗口
        CTRL-W j                跳转到下面的窗口
        CTRL-W k                跳转到上面的窗口
        CTRL-W l                跳转到右边的窗口
        CTRL-W t                跳转到最顶上的窗口
        CTRL-W b                跳转到最底下的窗口

        CTRL-W K                把当前窗口移到最上边
        CTRL-W H                把当前窗口移到最左边
        CTRL-W J                把当前窗口移到最下边
        CTRL-W L                把当前窗口移到最右边
        
        :qall                   
        :wall
        :wqall                  关闭保存所有窗口

3. 折叠

        :set foldmethod=indent 根据缩紧设置折叠
        zo          打开折叠
        zc          关闭折叠
        zf[range]   建立折叠 

        zfap        建立一段折叠

        zr          打开全部折叠
        zR
        zm          关闭折叠
        zM          编辑所有折叠

        zd          删除折叠

4. 比较

        vimdiff file1 file2     使用此命令进入vim,开启比较模式
        ]c                      下一个修改点
        [c                      上一个修改点
        :diffupdate             修改后可能没有及时更新高亮块,重新渲染
        :dp(diff put)           把不同点从光标位置移到比较窗口
        :do(diff obtain)        把不同点从比较窗口移到光标位置

5. 标签页

        :tabedit filename       创建标签页
        gt                      标签页跳转
        :tab split              创建新标签页
        :tabonly                关闭其他标签页
        :tabn                   下一个标签页

## 记录

有时我们需要很多命令组合使用,而且他们在一个文件中使用多次,我们可以使用记录命令保存这些操作.

        qa      启动记录,使用 a 寄存器
        q       结束记录
        3@a     执行 a 寄存器的操作

使用大写寄存器附加命令

        qAiaaaaq    在 a 寄存器中添加 iaaaa 命令

注意 此处的寄存器和复制时使用的寄存器是一致的,不要在记录使用 a 寄存器中 在使用 a 寄存器复制文字.

## 使用外部程序

命令 "!{motion}{program}" 用一个外部程序对一个文本块进行过滤。换句话说，它用一个文本块作为输入，执行一个由 {program} 指定的外部命令，然后用该程序的输出替代选中的文本块。

    !5Gsort<Enter>

表示对文件前 5 行使用 sort 命令排序

### 挂起与继续

        CTRL-Z      程序挂起
        fg          进入挂起的vim程序
