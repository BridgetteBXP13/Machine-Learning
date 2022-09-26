## Overview of Machine Learning (ML)
[Here](Overview%20of%20ML.pdf) is lovely pdf which shows a brief overview of ML.

## Data Exploration in C++
[Here](Data%20Exploration/Data%20Exploration%20in%20C%2B%2B.pdf) is a pdf about Data Exploration in C++ and the [data_exploration.cpp](Data%20Exploration/data_exploration.cpp) program. Note: It requires the [Boston.csv](Data%20Exploration/Boston.csv) input file.

## Linear Models

### Regression
In this [notebook](Linear%20Models/Regression/Regression.Rmd) we used a [Air Pollution](Linear%20Models/Regression/Air_Pollution.csv) dataset. It is also available in [pdf](Linear%20Models/Regression/Regression.pdf) form. In the notebook/pdf we did an overview of Linear Regression and created a few linear models with the air pollution dataset. First we cleaned the data set and filled in the missing values with means, then we divded the data into train and test sets. We plotted the different recorded factors. We experimented with different models, however none of them were very good at predicting one another. We believe this is because of the nature of the data and some of the data was very skewed. None the less we reviewed the summaries and explained the different metrics for judging the models. We compared the models based on the different graphs and metric values. 

### Classification
In this [notebook](Linear%20Models/Classification/Classification.Rmd) we used a [Tree Cover](Linear%20Models/Classification/covtype.csv) dataset. It is also available in [pdf](Linear%20Models/Classification/Classification.pdf) form. In the notebook/pdf we did an overview of Classification. We explored and cleaned the data, this dataset is very well done and had no empty values, it also is very large with nearly 600,000 observations. We did multiclass classification using Logistic Regression with the One vs All method. Then we used Naive Bayes Models and evaluated both. Then we evaluated the two with their metrics such as accurracy, sensitivity, specificity, kappa, ROC curves, AUC, and tried MCC but our dataset was too large and overflowed the function. Then we compared the two models and analyzed the benefits/drawbacks of the different metrics.