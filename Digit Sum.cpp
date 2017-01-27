{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fnil\fcharset0 Menlo-Bold;\f1\fnil\fcharset0 Menlo-Regular;\f2\fswiss\fcharset0 ArialMT;
}
{\colortbl;\red255\green255\blue255;\red53\green65\blue117;\red255\green255\blue234;\red38\green38\blue38;
\red133\green0\blue2;\red26\green26\blue26;\red17\green137\blue135;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\b\fs26 \cf2 \cb3 \expnd0\expndtw0\kerning0
int
\f1\b0 \cf4  
\f0\b \cf5 digit_sum
\f1\b0 \cf4 (
\f0\b \cf2 long
\f1\b0 \cf4  
\f0\b \cf2 long
\f1\b0 \cf4  number) \{\
	\
	//long type has a width of 32 bits 
\f2\b\fs32 \cf6 \cb1 2,147,483,647
\f1\b0\fs26 \cf4 \cb3 \
	//long long has a width of 64 bits 
\f2\b\fs32 \cf6 \cb1 9,223,372,036,854,775,807
\f1\b0\fs26 \cf4 \cb3 \
\
    
\f0\b \cf2 int
\f1\b0 \cf4  sumDigits 
\f0\b =
\f1\b0  \cf7 0\cf4 ;\
    
\f0\b \cf2 int
\f1\b0 \cf4  digit 
\f0\b =
\f1\b0  \cf7 0\cf4 ;\
    \
    
\f0\b if
\f1\b0  (number
\f0\b <
\f1\b0 \cf7 0\cf4 )\
        number
\f0\b =
\f1\b0 number
\f0\b *-
\f1\b0 \cf7 1\cf4 ;\
        \
    
\f0\b while
\f1\b0 (number
\f0\b >
\f1\b0 \cf7 0\cf4 )\{\
        digit
\f0\b =
\f1\b0 number
\f0\b %
\f1\b0 \cf7 10\cf4 ;\
        number
\f0\b =
\f1\b0 number
\f0\b /
\f1\b0 \cf7 10\cf4 ;\
        sumDigits
\f0\b =
\f1\b0 sumDigits
\f0\b +
\f1\b0 digit;\
    \}\
    \
    
\f0\b return
\f1\b0  sumDigits;\
    \
\}}