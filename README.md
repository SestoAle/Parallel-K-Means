# Parallel K Means
A parallel implementation of K-Means algorithm in C++ and OpenMP.

<p align="center">
<img  src="https://i.imgur.com/THQHtmv.png" width="90%" height="90%"/>
</p>

The task of k-means is to divide points within a space in K groups based on their characteristics. It is based on few steps:
1. generate N points;
2. generate K centroids that represent K clusters;
3. for each point, compute the distance between the point and all of the clusters and assign the point
to the nearest cluster;
4. update the centroid’s characteristics, specially its coordinates, based on the new points inside the
cluster;
5. repeat from 3 until reaching a maximum number of iterations or until the clusters won’t move.

## Implementation
The implementation covres both sequential and parallel version, in **C++** and **OpenMP**.

#### Sequential version
Two classes are defined:
* Point.h
  * 2D points chosen randomly;
  * ```x_coord```, ```y_coord```, ```cluster_id```;
  * ```setter()``` and ```getter()``` methods.
* Cluster.h
  * 2D points chosen randomly at first;
  * ```x_coord```, ```y_coord```, ```size```, ```new_x_coord```, ```new_y_coord```;
  * ```setter()``` and ```getter()``` methods and others to update the coordinates of the centroids.
  
The file ```main_sequential``` starts the sequential version:
* in this program, points and clusters are 2D points chosen randomly;
* the first functions initialize clusters and points;
* after that, there is a while loop where are the 2 most important functions:
  * ```compute_distance()```; 
  * ```update_clusters()```;
  
#### Parallel version
The program is mostly parallelizable in the ```compute_distance()``` function and we can parallelize the outer for.
OpenMP was choosen in order to parallelize the computing:

* **Private variables** for each thread: ```min_distance``` and ```min_index```;
* **Firstprivate variables** for each thread: ```points_size``` and ```clusters_size```;
* **Shared variable**: vector of points and vector of clusters;
* since the amount for computation is equal for each thread, it was chosen a **static scheduling**.

## Experiments and results
Here is a table that shows the speedup analysis:
<p align="center">
<img  src="https://i.imgur.com/V5aqr5q.png" width="100%" height="100%"/>
</p>

Here an example of the execution of the program plotted with Gnuplot:
<p align="center">
<img  src="https://i.imgur.com/gxbj2hf.png" width="50%" height="50%"/>
</p>

## Reports
A copy of the report (italian) can be found 
<a href="https://github.com/SestoAle/Parallel-K-Means/raw/master/reports/report.pdf" download="report.pdf">here</a>.

A copy of the presentation can be found
<a href="https://github.com/SestoAle/Parallel-K-Means/raw/master/reports/presentation.pdf" download="presentation.pdf">here</a>.

## License
Licensed under the term of [MIT License](https://github.com/SestoAle/Parallel-K-Means/blob/master/LICENSE).
