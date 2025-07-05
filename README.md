# 员工管理系统项目说明

## 项目简介

本项目是基于C++语言开发的员工管理系统，旨在实现内部员工的信息管理，包括不同岗位（如销售员、销售经理、经理）的信息录入、修改、查询与删除等基础管理功能。

## 面向对象特性

### 1. 继承与多态

* 继承性：项目采用继承结构，定义抽象基类`Staff`，不同的员工类型如`Salesman`、`Manager`、`SalesManager`均继承自该基类。
* 多态性：通过虚函数机制，实现不同职位员工的具体功能调用，提高代码的灵活性与扩展性。

### 2. 封装性

* 成员变量全部采用`private`或`protected`权限修饰，通过公共接口函数提供外部访问，确保类的内部数据安全性。

## 核心类与函数说明

### 类结构

* Staff（抽象基类）

  * 虚函数：`showInfo()`、`getJob()`

* Salesman（销售员类）

  * 重写函数：`showInfo()`、`getJob()`

* Manager（经理类）

  * 重写函数：`showInfo()`、`getJob()`

* SalesManager（销售经理类）

  * 重写函数：`showInfo()`、`getJob()`

* ManagementSystem（管理系统类）

  * 功能函数：`addStaff()`（添加员工）、`removeStaff()`（删除员工）、`modifyStaff()`（修改员工）、`displayStaff()`（展示所有员工信息）
  * 文件操作函数：`loadData()`（从文件加载数据）、`saveData()`（数据保存到文件）

## 核心技术实现

### 内存管理

* 使用`new`动态分配员工对象内存，并通过析构函数显式调用`delete`释放内存，避免内存泄漏。

### 文件IO

* 使用C++标准库中的`fstream`进行员工数据文件（staff.txt）的读写操作，实现数据的持久化存储。

### STL容器

* 使用`vector`容器存储员工对象的指针，实现动态的内存管理与扩展。

## 项目目录结构

```
manage_system/
├── main.cpp                          # 程序入口
├── ManagementSystem.cpp/.h           # 系统管理逻辑实现
├── Staff.cpp/.h                      # 抽象基类定义
├── Manager.cpp/.h                    # 经理类实现
├── SalesManager.cpp/.h               # 销售经理类实现
├── Salesman.cpp/.h                   # 销售员类实现
├── staff.txt                         # 员工信息存储文件
└── manage_system.sln                 # Visual Studio项目文件
```


