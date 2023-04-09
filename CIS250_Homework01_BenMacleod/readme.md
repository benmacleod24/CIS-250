# Employee Management System

Benjamin MacLeod
<br>
February 28th, 2023
<br>
CIS 250

## Overview

Employee management system used to sort & review employees at a company. The data source is a `comma seperated list` that is parsed into two specific data structures.

## Data Structures

The data structures of this program are fairly basic, but may be complex. The "Employee" structure contains all employee properties as well as their respective department's properties (not just their ID), allowing access to all employee properties within a single model. The "department" structure includes all the properties of a department. Structures are stored under two vectors, one for employees and one for departments. Extracting each department into a vector (no duplicate departments) made it easier to perform department related logic without having to traverse employees before departments, with the benefit of faster response times to the user on department tasks.

## Project Thoughts

Took me a while to figure out how I wanted to approach this project, but once I sat down and put some thorough thought into the data structures and how to lay them out, it was a breeze. It was important to me that the models are easy for other engineers to understand, thus why I extracted departments into their own vector for data processing. I really enjoyed this project and it's complexities.
