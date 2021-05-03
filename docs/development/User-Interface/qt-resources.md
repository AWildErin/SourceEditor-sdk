# Qt Resources
Since we use Qt as our GUI library we have added a few useful search paths using Qt to help make it a bit easier to add images, stylesheets and more to your project.

## Types of search paths

For the search paths, you will use code like this to access it:
```cpp
QFile file("resources:/stylesheets/sourceeditor.qss");

// Break down
QFile file("<searchpath>:/<file relative to search path");
```

| Key       | Directory        | Summary                                            |
|-----------|------------------|----------------------------------------------------|
| resources | <root>/resources | Allows you to access files inside the root folder. |