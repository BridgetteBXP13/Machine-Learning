## Overview of Machine Learning (ML)
[Here](Overview%20of%20ML.pdf) is lovely pdf which shows a brief overview of ML.

## Data Exploration in C++
[Here](Data%20Exploration/Data%20Exploration%20in%20C%2B%2B.pdf) is a pdf about Data Exploration in C++ and the [data_exploration.cpp](Data%20Exploration/data_exploration.cpp) program. Note: It requires the [Boston.csv](Data%20Exploration/Boston.csv) input file.

## Linear Models

### Regression
In this [notebook](Linear%20Models/Regression/Regression.Rmd) we used a [Air Pollution](Linear%20Models/Regression/Air_Pollution.csv) dataset. It is also available in [pdf](Linear%20Models/Regression/Regression.pdf) form. In the notebook/pdf we did an overview of Linear Regression and created a few linear models with the air pollution dataset. First we cleaned the data set and filled in the missing values with means, then we divded the data into train and test sets. We plotted the different recorded factors. We experimented with different models, however none of them were very good at predicting one another. We believe this is because of the nature of the data and some of the data was very skewed. None the less we reviewed the summaries and explained the different metrics for judging the models. We compared the models based on the different graphs and metric values. 

### Classification
In this [notebook](Linear%20Models/Classification/Classification.Rmd) we used a [Tree Cover](Linear%20Models/Classification/covtype.csv) dataset. It is also available in [pdf](Linear%20Models/Classification/Classification.pdf) form. In the notebook/pdf we did an overview of Classification. We explored and cleaned the data, this dataset is very well done and had no empty values, it also is very large with nearly 600,000 observations. We did multiclass classification using Logistic Regression with the One vs All method. Then we used Naive Bayes Models and evaluated both. Then we evaluated the two with their metrics such as accurracy, sensitivity, specificity, kappa, ROC curves, AUC, and tried MCC but our dataset was too large and overflowed the function. Then we compared the two models and analyzed the benefits/drawbacks of the different metrics.

### Machine Learning with C++ from Scratch
In this [pdf](ML%20Algorithms%20from%20Scratch/Machine%20Learning%20with%20C%2B%2B.pdf) we do an overview of our C++ maching learning programs [Logistic Regression](ML%20Algorithms%20from%20Scratch/LogisticRegression.cpp) and [Naive Bayes](ML%20Algorithms%20from%20Scratch/NaiveBayes.cpp) from scratch. In the pdf it will go over the purpose, input, output, logic, functions, and metrics for each of our C++ machine learning logistic regression and naive bayes programs. For this we used the [titanic dataset](ML%20Algorithms%20from%20Scratch/titanic_project.csv) to classify if a person survivied or not.

#### Logistic Regression

Our logistic regression model only used the 'sex' predictor and utlized vector and matrix mulitplication in C++ to perform the neccessary calculations for the logistic regression algorithm. It takes the [titanic dataset](ML%20Algorithms%20from%20Scratch/titanic_project.csv) as it's file input, if not available in the directory then it will display an error message in the terminal to the user. It will then organize the data into test/train vectors, close the file, and then create the logisitc regegression model. After that it will display the evaluation to the user showing the confusion matrix, accuracy, spensitiivty, specificity, and how long it took to create the model in microseconds. More detail can be seen in the pdf above.

#### Naive Bayes

Our naive bayes model only used all the predictors except person including person's class, sex, and age and utlized vector and matrix mulitplication in C++ to perform the neccessary calculations for the naive bayes algorithm and probability calculations. Note: for age we divided it into 5 categories as follows: Kids (0-12), Teens (13-19), Adults (20-39), Mid Adults(40-59), and Seniors (60+). It takes the [titanic dataset](ML%20Algorithms%20from%20Scratch/titanic_project.csv) as it's file input, if not available in the directory then it will display an error message in the terminal to the user. It will then organize the data into test/train vectors, close the file, and then create the naive bayes model. After that it will display the evaluation to the user showing the probabilty matrix for each predictor, the predictions made overall if they survivied or not, the evaluation confusion matrix, accuracy, spensitiivty, specificity, and how long it took to create the model in microseconds. More detail can be seen in the pdf above.