# Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
# Project developers.  See the top-level LICENSE file for dates and other
# details.  No copyright assignment is required to contribute to VisIt.

#****************************************************************************/
# Modifications:
#
#****************************************************************************/

# deps for flow
SET(visit_flow_sources src/__init__.py
                       src/core/__init__.py
                       src/core/common.py
                       src/core/errors.py
                       src/core/filter_graph.py
                       src/core/log.py
                       src/core/property_tree.py
                       src/core/registry.py
                       src/core/state_control.py
                       src/core/workspace.py
                       src/filters/__init__.py
                       src/filters/cmd.py
                       src/filters/file_ops.py
                       src/filters/imagick.py
                       src/filters/management.py
                       src/filters/npy_ops.py
                       src/filters/pyocl_batch.py
                       src/filters/pyocl_compile.py
                       src/filters/pyocl_env.py
                       src/filters/pyocl_kernels.py
                       src/filters/pyocl_ops.py
                       src/filters/script_pipeline.py
                       src/parser/__init__.py
                       src/parser/generator.py
                       src/parser/parser.py)

PYTHON_ADD_DISTUTILS_SETUP(visit_flow_py_setup
                           site-packages
                           setup.py
                           ${visit_flow_sources})





