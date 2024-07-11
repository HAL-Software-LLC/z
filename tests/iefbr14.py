"""iefbr14.py - A python implementation of the MVS "do nothing" module, IEFBR14."""

import unittest

#from z.assembly import *
#from z.registers import *
#from z.instructions import BR, LTR, LHI

@RSECT
class IEFBR14:
  """
  A python implementation of the MVS "do nothing" module, IEFBR14.
  """
  RMODE(24)
  AMODE(24)
  LHI(R15, 0)
  LTR(R15, R15)      
  BR(R14)

class AssemblyTests(unittest.TestCase):
  """
  Verify that the module was assembled correctly.
  """
  def test_assembly(self):
    """
    """
    self.assertEqual(bytes(IEFBR14), b'A7F8000012FF070E')

class ExecutionTests(unittest.TestCase):
  """
  Verify that the module executes as expected.
  """
  def test_execution(self):
    """
    Execute the mofule. Confirm that R15 is set to 0 and that the condition codes are cleared.
    """
    IEFBR14()
    self.assertEqual(R15, 0)
    self.assertEqual(PSW.cc, 0)
