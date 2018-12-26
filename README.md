# ANN-MovieRatings
## WARNING: I made this project back before I knew practically anything about Machine Learning, it was my first dive in. The ANN and GA implementations I think are good and perhaps worthwhile, but the actual experiment in this project is a bit... ridiculous. At the very least the project can show the general workflow of how an ANN and GA works, but not so much a real ML project.

A c++ project using an ANN and Genetic Algorithm to predict what a user will rate a movie.

When the program is ran, the user can put in certain values for the neural network and genetic algorithm. A good configuration that I found is:
- Do not use basic criteria.
- 1 hidden layer.
- 15 hidden layer nodes.
- 15000+ generations.
- 20 organisms per generation.
- 0.1 mutation probability.
- Any learning rate. (Learning rate is irrelevant due to an error I made)

This program rates movies based on stats like if it is animated, and how well it fits into a genre. It does not take into account things like quality and actors. It can get very accurate to the training set, getting as close as 0.1 for me. The error rate is how far off each movie rater is to rating the movies, 0 is the best.
