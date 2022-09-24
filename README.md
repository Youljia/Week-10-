# Week-10-

# 数据结构与算法

## 二分搜索树(Binary Search)

* 树结构-->是一种天然的数据结构

  ​	例如  公司的部门管理图

* 二叉树

  * 一个节点  including  本身数据e,左节点，右节点

    ```c++
    	int e;
    	Node* left;  //左孩子
    	Node* right; //右孩子
    //左右孩子是可以为空的！
    ```

* 二分搜索树的定义

  * 是一个二叉树
  * 一个节点的左孩子的元素都小于该节点元素，右孩子的元素都大于该节点的元素 --> *不包含相等的元素*
  * 每一颗子树也是一个二分搜索树  -->  *天然的递归结构*

* 二分搜索树的遍历操作

  * 深度遍历 -- 递归实现

    * 前序遍历

      *先操作节点，再操作左子树，最后右子树*

      ```c++
      	if (node == nullptr)
      		return;
      	cout << node->e << "  ";
      	pre_traverse(node->left);
      	pre_traverse(node->right);
      ```

      

    * 中序遍历

      *先操作左子树，再操作节点，最后右子树*

      ```c++
      	if (node == nullptr)
      		return;
      	in_traverse(node->left);
      	cout << node->e << "  ";
      	in_traverse(node->right);
      //让树的元素从小到大输出
      ```

      

    * 后序遍历

      *先操作左子树，再操作右子树，最后节点*

      ```c++
      	if (node == nullptr)
      		return;
      	post_traverse(node->left);
      	post_traverse(node->right);
      	cout << node->e << "  ";
      ```

      

  * 广度遍历 -- 依靠队列，非递归实现

    * 层序遍历

      ```c++
      	queue<Node*> q;
      	q.push(this->root);
      	while (!q.empty())
      	{
      		Node* cur = q.front();
      		q.pop();
      		cout << cur->e << " ";
      		if (cur->left != nullptr)
      			q.push(cur->left);
      		if (cur->right != nullptr)
      			q.push(cur->right);
      	}
      ```


* 基本操作
  * 寻找最大最小值
    * 左走到尽头，最小值
    * 右走到尽头最大 值

## 集合与映射

### 集合

* 是一种高层数据结构，底部实现可以依托于其他的数据结构
* 特点 - - > 元素的唯一性，即集合中没有重复元素
* 实现方式
  * 基于二分搜索树
    * 时间复杂度  add --> O(logn)
  * 基于链表
    * 时间复杂度 add --> O(n)

### 映射

* 和集合一样，也是高层数据结构
* 特点 --> 在每一个节点，多了一个key.即一个key，一个value
* 操作 --> 通常时通过键来访问，修改，删除value的
