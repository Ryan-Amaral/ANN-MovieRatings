# ANN-MovieRatings
A c++ project using an ANN and Genetic Algorithm to predict what a user will rate a movie.

When the program is ran, the user can put in certain values for the neural network and genetic algorithm. A good configuration that I found is:
- Do not use basic criteria.
- 1 hidden layer.
- 10 hidden layer nodes.
- 15000+ generations. (the program crashed on my computer at around 25000)
- 20 organisms per generation.
- 0.1 mutation probability.
- 50 learning rate. (any value seems to work, but 50 seemed more consistent to me)

This program rates movies based on stats like if it is animated, and how well it fits into a genre. It does not take into account things like quality and actors. It can get very accurate to the training set, getting as close as 0.3 for me. The error rate is how far off each movie rater is to rating the movies, 0 is the best.
