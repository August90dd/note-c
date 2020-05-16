/*
 * 防止头文件多次包含:
 * 首次包含此头文件时, 由于未定义宏BOOLEAN_H, 预处理器允许保留在#ifndef和#endif之间的多行内容.
 * 但如果再次包含此文件, 预处理器将#ifndef和#endif之间的多行内容删除.
 */
#ifndef BOOLEAN_H
#define BOOLEAN_H

#define TRUE    1
#define FALSE   0

#endif
