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

MAKE_CLEAN += tags cscope.files cscope.out  doc/html/*
