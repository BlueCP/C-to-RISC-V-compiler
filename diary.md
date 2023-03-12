# Diary

## Main milestones

- In general, the project will progress as Roshan adds more classes to the AST to support the various features detailed in the specification, while Corey fills in the codegen and handles the other parts of the project, such as linking all the files together and preparing the environment.
- The codegen is highly dependent on the structure and properties of the AST classes, so we will aim for a system like this:
  - Roshan adds a few AST classes and prepares them to be filled in with codegen.
  - Corey adds the codegen, and informs Roshan if the AST classes need to be changed to faciliate codegen if any issues arise.
  - Once the AST classes and codegen are all completed for a new set of features, the compiler is tested to see if it passes the test cases that it was not able to pass before.
  - This is a cyclical development model and it is necessary here because of how closely intertwined the AST classes and codegen are. It is not possible to work independently, as was the case for some previous projects.
- We aim to complete all of the basic features by the middle of the W/C 13/3, so that we can start adding intermediate features that week.
- For the W/C 20/3, we aim to finish all of the intermediate features, and if there is time, we can start adding some of the advanced features as well.

### Milestone status:

- Basic features: all AST classes completed, codegen in progress.
- Intermediate features: most AST classes completed, codegen in progress.
- Advanced features: no progress yet.

## 6/2/23

Roshan has written up an ast and on wednesday will implement the first part (the first block of goals)

Corey will write the code gen and handle the admin parts

## 12/3/23

Roshan:
- In theory, all of the AST classes for the basic features and most of the classes for the intermediate features have been implemented, well ahead of schedule.
- However, this was achieved by dumping a large number of hours into this coursework, which may not be sustainable as other coursework deadlines approach.
- Nonetheless, based on my rate of progress so far, I think it will be feasible to implement a good number of advanced features by the deadline.
- It remains to be seen whether these classes are sufficient. It was not possible to test them as I went along, so there are likely many bugs that will need to be fixed once codegen is completed and we can run the compiler.
- UPDATE: all AST classes for intermediate features have now been completed.

## W/C 13/3/23

Roshan:
- This week, we have one coursework deadline and a lab containing a significant amount of work, so it is unlikely we will be able to put as much time into the compiler.
- However, based on the fast progress with the AST classes so far, having written all classes needed for the intermediate features, I can start work on the advanced features.
- I also expect to have to modify some of my classes based on feedback from Corey. Although I have tried to make my AST classes as compatible as possible with codegen, I have not actually implemented codegen so there are inevitably going to be things I did not foresee.