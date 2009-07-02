QMAKE_EXTRA_TARGETS+=depend
INCLUDES+=/usr/include/c++/4.3.3/
INCLUDE_PATHS+=-I/usr/include/c++/4.3.3 \
    -I/home/rasjani/localsrc/squared/src/lib/ \
    -I/home/rasjani/localsrc/squared/src/game/ \
    -I/usr/include/SDL \
    -I/usr/include/c++/4.3/i486-linux-gnu/ \
    -I/usr/include/linux \
    -I/usr/include/c++/4.3/tr1/ \



contains(TEMPLATE,subdirs) {
    depend.CONFIG=recursive
    depend.target=depend
    depend.depends=FORCE
} else {
    depend.target=depend
    depend.depends=FORCE
    depend.commands=makedepend -- $$INCLUDE_PATHS -- ${SOURCES}
}
