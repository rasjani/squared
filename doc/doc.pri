QMAKE_EXTRA_UNIX_TARGETS += doc
doc.commands = @doxygen doc/Doxyfile
doc.depends = FORCE
