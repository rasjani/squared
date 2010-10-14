unix {
    QMAKE_EXTRA_TARGETS += doc
    doc.commands = @doxygen doc/Doxyfile
    doc.depends = FORCE
}
