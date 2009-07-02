include(config.pri)
include(doc/doc.pri)

TEMPLATE = subdirs
SUBDIRS= src


QMAKE_EXTRA_TARGETS+=ctags
ctags.depends=FORCE
ctags.commands=ctags --exclude=Makefile -R src/ 

QMAKE_EXTRA_TARGETS+=cscope
cscope.depends=FORCE
cscope.commands=find src -name "*.h" -print > ./cscope.files ;
cscope.commands+=find src -name "*.src" -print >> ./cscope.files ;
cscope.commands+=cscope -b -i./cscope.files 

QMAKE_CLEAN += tags cscope.files cscope.out  doc/html/* valgrind.log Makefile.bak

QMAKE_EXTRA_TARGETS += leakcheck 
leakcheck.target=valgrind.log
contains(DEFINES,TIMEDEXECUTION) {
    leakcheck.commands=LD_LIBRARY_PATH=. valgrind --leak-check=full --show-reachable=yes --suppressions=squared.supp ./squared 2> ./valgrind.log
    leakcheck.depends=FORCE
} else {
    leakcheck.commands=@echo "Run 'qmake TIMEDEXECUTION=on' before using this target"
}
leakcheck.depends=FORCE
